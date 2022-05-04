<template>
  <v-card>
    <v-card-title>
      Sensors
      <v-spacer></v-spacer>
      <v-text-field
          v-model="search"
          append-icon="mdi-magnify"
          label="Search"
          single-line
          hide-details
      ></v-text-field>
      <v-btn @click="addSensor">Add Sensor</v-btn>
    </v-card-title>
    <v-data-table
        :headers="headers"
        :items="sensors"
        :search="search"
        @click:row="editSensor"
    ></v-data-table>
    <SensorDialog
        :opened="dialogVisible"
        :sensor="selectedSensor"
        @refresh="refreshList"
    ></SensorDialog>
  </v-card>
</template>

<script>
import api from "../api";
import SensorDialog from "@/components/SensorDialog";
import router from "@/router";
export default {
  name: "SensorList",
  components: {SensorDialog},
  data() {
    return {
      sensors: [],
      search: "",
      headers: [
        {
          text: "Sensor",
          align: "start",
          sortable: false,
          value: "name",
        },
        { text: "Description", value: "description" },
        { text: "MaxValue", value: "maxValue" },
      ],
      dialogVisible: false,
      selectedSensor: {},
    };
  },
  methods: {

    editSensor(sensor) {
      this.selectedSensor = sensor;
      this.dialogVisible = true;
    },
    addSensor() {
      this.dialogVisible = true;
    },
    async refreshList() {
      this.dialogVisible = false;
      this.selectedSensor = {};
      this.sensors = await api.sensors.allSensors();
    },
  },
  async created() {
    if (!this.$store.getters["auth/isAdmin"]) {
      await this.$store.dispatch("auth/logout");
      await router.push("/");
    } else {
      await this.refreshList();
    }
  },
};
</script>

<style scoped></style>