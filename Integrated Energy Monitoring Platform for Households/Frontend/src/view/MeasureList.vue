<template>
  <v-card>
    <v-card-title>
      Measurements
      <v-spacer></v-spacer>
      <v-text-field
          v-model="search"
          append-icon="mdi-magnify"
          label="Search"
          single-line
          hide-details
      ></v-text-field>
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
<!--     <vue-bar-graph
        :points=[]
        :show-y-axis="true"
        :show-x-axis="true"
        :width="400"
        :height="200"
        :show-values="true"
        :use-custom-labels="true"
        :labels="[]"
    />-->
  </v-card>
</template>

<script>
import api from "../api";
import router from "@/router";
import UserDialog from "@/components/UserDialog";
/*import VueBarGraph from 'vue-bar-graph';*/
import SockJS from "sockjs-client";
import Stomp from "webstomp-client";
export default {
  name: "MeasureList",
  components: { UserDialog},
  data() {
    return {
      users: [],
      search: "",
      headers: [
        {
          align: "start",
          sortable: false,
          value: "name",
        },
        { text: "Energy Consumption", value: "energyConsumption" },
        { text: "Timestamp", value: "timestamp" },
        { text: "Sensor Id", value: "sensorId" },
      ],
      dialogVisible: false,
      selectedUser: {},
    };
  },
  methods: {

    web_sockets() {
      this.socket = new SockJS("https://ds2020-30431-pasc-andreea-1-be.herokuapp.com/websockets");
      //this.socket = new SockJS("http://localhost:8088/websockets");
      this.stompClient = Stomp.over(this.socket);
      this.stompClient.connect(
          {"Access-Control-Allow-Origin": "*"},
          () => {
            this.connected = true;

            this.stompClient.subscribe("/measures/message", tick => {
              let response = tick.body;
              alert(response);
              console.log(response)
            });

            console.log("websockets")
          },
          error => {
            console.log(error);
            this.connected = false;
          }
      );
    },

    async refreshList() {
      this.dialogVisible = false;
      this.selectedUser = {};
      this.users = await api.users.getConsumption(this.$store.getters["auth/getUserId"]);
      console.log(this.users);
    },
  },

  async created() {
    this.web_sockets();
    if(!this.$store.getters["auth/isCustomer"]){
      await this.$store.dispatch("auth/logout");
      await router.push("/");
    } else{
      await this.refreshList();
    }
  },

};
</script>

<style scoped></style>