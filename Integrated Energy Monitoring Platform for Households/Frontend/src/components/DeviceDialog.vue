<template>
  <v-dialog
      transition="dialog-bottom-transition"
      max-width="600"
      :value="opened"
  >
    <template>
      <v-card>
        <v-toolbar color="primary" dark>
          {{ isNew ? "Create device" : "Edit device" }}
        </v-toolbar>
        <v-form>
          <v-text-field v-model="device.averageEnergyConsumption" label="avgEC" />
          <v-text-field v-model="device.description" label= "Description" />
          <v-text-field v-model="device.location" label= "Location" />
          <v-text-field v-model="device.maxEnergyConsumption" label= "maxEC" />
          <v-text-field v-model="device.userId" label= "User Id" />
          <v-text-field v-model="device.sensorId" label= "Sensor Id" />
        </v-form>
        <v-card-actions>
          <v-btn @click="persist">
            {{ isNew ? "Create" : "Save" }}
          </v-btn>
          <v-btn @click="deleteDevice">Delete Device</v-btn>
        </v-card-actions>
      </v-card>
    </template>
  </v-dialog>
</template>

<script>
import api from "../api";
export default {
  name: "DeviceDialog",
  props: {
    device: Object,
    opened: Boolean,
  },
  methods: {
    persist() {
      if (this.isNew) {
        api.devices
            .create({
              averageEnergyConsumption: this.device.averageEnergyConsumption,
              description: this.device.description,
              location:this.device.location,
              maxEnergyConsumption:this.device.maxEnergyConsumption,
              userId:this.device.userId,
              sensorId:this.device.sensorId,
            })
            .then(() => this.$emit("refresh"));
      } else {
        api.devices
            .update({
              id: this.device.id,
              averageEnergyConsumption: this.device.averageEnergyConsumption,
              description: this.device.description,
              location:this.device.location,
              maxEnergyConsumption:this.device.maxEnergyConsumption,
              userId:this.device.userId,
              sensorId:this.device.sensorId,
            })
            .then(() => this.$emit("refresh"));
      }
    },

    deleteDevice(){
      api.devices
          .delete({
            id: this.device.id,
          })
          .then(() => this.$emit("refresh"));
    },
  },
  computed: {
    isNew: function () {
      return !this.device.id;
    },
  },
};
</script>

<style scoped></style>