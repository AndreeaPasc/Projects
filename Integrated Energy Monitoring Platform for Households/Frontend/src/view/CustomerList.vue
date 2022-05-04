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
      <v-btn @click="consumption">Consumption</v-btn>
    </v-card-title>
    <v-data-table
        :headers="headers"
        :items="users"
        :search="search"
    ></v-data-table>
    <UserDialog
        :opened="dialogVisible"
        :user="selectedUser"
        @refresh="refreshList"
    ></UserDialog>
<!--    <vue-bar-graph
        :points="[3,5,2,5,4]"
        :width="400"
        :height="200"
    />-->
  </v-card>
</template>

<script>

import UserDialog from "@/components/UserDialog";
import api from "@/api";
import router from "@/router";

export default {
  name: "CustomerList",
  components: {UserDialog},
  data() {
    return {
      users:[],
      search: "",
      headers: [
        {
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
      selectedUser: {},
    };
  },
  methods: {
    consumption(){
      router.push("./measures");
    },

    async refreshList() {
      this.dialogVisible = false;
      this.selectedUser = {};
      this.users = await api.users.getDevices(this.$store.getters["auth/getUserId"]);
    },
  },
  async created() {
    if (!this.$store.getters["auth/isCustomer"]) {
      await this.$store.dispatch("auth/logout");
      await router.push("/");
    } else {
      await this.refreshList();
    }
  },
};
</script>

<style scoped></style>