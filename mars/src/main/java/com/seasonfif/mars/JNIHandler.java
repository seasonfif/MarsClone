package com.seasonfif.mars;

public class JNIHandler {

    static {
        System.loadLibrary("mars");
    }


    public static String init(String flag){
        return initMars(flag);
    }

    public static int confi(String conf){
        return config(conf);
    }

    public static native String initMars(String flag);

    public static native int config(String conf);

}
