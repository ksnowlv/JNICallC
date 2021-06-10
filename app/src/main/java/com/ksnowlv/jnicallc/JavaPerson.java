package com.ksnowlv.jnicallc;

public class JavaPerson {


    private long mNativePerson;

    public JavaPerson()
    {
        mNativePerson = init();
    }

    public int getAge()
    {
        return this.native_getAge(mNativePerson);
    }

    public void setAge(int age)
    {
        native_setAge(mNativePerson, age);
    }

    public String getName() {
        return native_getName(mNativePerson);
    }

    public void setName(String name) {
        native_setName(mNativePerson, name);
    }


    @Override
    protected void finalize() throws Throwable {

        if (mNativePerson != 0) {
            finalizer(mNativePerson);
        }

        super.finalize();
    }

    static {
        System.loadLibrary("jniPerson");
    }

    private native long  init();
    private native void finalizer(long aPerson);
    private native int native_getAge(long aPerson);
    private native void native_setAge(long aPerson, int age);
    private native String native_getName(long aPerson);
    private native void native_setName(long aPerson, String name);
}
