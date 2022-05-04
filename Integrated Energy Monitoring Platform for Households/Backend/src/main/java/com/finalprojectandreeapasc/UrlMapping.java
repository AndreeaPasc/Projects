package com.finalprojectandreeapasc;

public class UrlMapping {
    public static final String API_PATH = "/api";
    public static final String ENTITY = "/{id}";

    public static final String AUTH = API_PATH + "/auth";
    public static final String SIGN_IN = "/sign-in";
    public static final String SIGN_UP = "/sign-up";

    public static final String USERS = API_PATH + "/users";
    public static final String DEVICES = API_PATH + "/devices";
    public static final String SENSORS = API_PATH + "/sensors";
    public static final String CONSUMPTIONS = API_PATH + "/measures";

    public static final String WEBSOCKET = API_PATH + "/websockets";
    public static final String MESSAGE = "/messages";
    public static final String SEND = USERS + MESSAGE;
}
