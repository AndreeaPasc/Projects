import Vue from "vue";
import VueRouter from "vue-router";
import Login from "../view/Login";
import UserList from "../view/UserList.vue";
import { auth as store } from "../store/auth.module";
import DeviceList from "@/view/DeviceList";
import SensorList from "@/view/SensorList";
import CustomerList from "@/view/CustomerList";
import MeasureList from "@/view/MeasureList";

Vue.use(VueRouter);

const routes = [
    {
        path: "/",
        name: "Login",
        component: Login,
    },
    {
        path: "/users",
        name: "Users",
        component: UserList,
        beforeEnter: (to, from, next) => {
            if (store.getters.isAdmin) {
                next();
            } else {
                next({ name: "Devices" });
            }
        },
    },
    {
        path: "/devices",
        name: "Devices",
        component: DeviceList,
        beforeEnter: (to, from, next) => {
            if (store.getters.isAdmin) {
                next();
            } else {
                next({ name: "Login" });
            }
        },
    },
    {
        path: "/sensors",
        name: "Sensors",
        component: SensorList,
        beforeEnter: (to, from, next) => {
            if (store.getters.isAdmin) {
                next();
            } else {
                next({ name: "Login" });
            }
        },
    },
    {
        path: "/customers",
        name: "Customers",
        component: CustomerList,
        beforeEnter: (to, from, next) => {
            if (store.getters.isCustomer) {
                next();
            } else {
                next({ name: "Login" });
            }
        },
    },
    {
        path: "/measures",
        name: "Measurements",
        component: MeasureList,
        beforeEnter: (to, from, next) => {
            if (store.getters.isCustomer) {
                next();
            } else {
                next({ name: "Login" });
            }
        },
    },
    {
        path: "/about",
        name: "About",
        // route level code-splitting
        // this generates a separate chunk (about.[hash].js) for this route
        // which is lazy-loaded when the route is visited.
        component: () =>
            import(/* webpackChunkName: "about" */ "../view/About.vue"),
    },
];

const router = new VueRouter({
    routes,
});

export default router;