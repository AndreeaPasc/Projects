<template>
  <v-card>
    <v-card-title>
      Devices
      <v-spacer></v-spacer>
      <v-text-field
          v-model="search"
          append-icon="mdi-magnify"
          label="Search"
          single-line
          hide-details
      ></v-text-field>
      <v-btn @click="addDevice">Add Device</v-btn>
    </v-card-title>
    <v-data-table
        :headers="headers"
        :items="devices"
        :search="search"
        @click:row="editDevice"
    ></v-data-table>
    <DeviceDialog
        :opened="dialogVisible"
        :device="selectedDevice"
        @refresh="refreshList"
    ></DeviceDialog>
  </v-card>
</template>

<script>
import api from "../api";
import DeviceDialog from "@/components/DeviceDialog";
import router from "@/router";
export default {
  name: "DeviceList",
  components: { DeviceDialog },
  data() {
    return {
      devices: [],
      search: "",
      headers: [
        {
          text: "Device",
          align: "start",
          sortable: false,
          value: "name",
        },
        { text: "AvgEC", value: "averageEnergyConsumption" },
        { text: "MaxEC", value: "maxEnergyConsumption" },
        { text: "Description", value: "description" },
        { text: "Location", value: "location" },
        { text: "UserId", value: "userId" },
        { text: "SensorId", value: "sensorId" },
      ],
      dialogVisible: false,
      selectedDevice: {},
    };
  },
  methods: {

    editDevice(device) {
      this.selectedDevice = device;
      this.dialogVisible = true;
    },
    addDevice() {
      this.dialogVisible = true;
    },
    async refreshList() {
      this.dialogVisible = false;
      this.selectedDevice = {};
      this.devices = await api.devices.allDevices();
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