class MillisDelay {
    public:
        MillisDelay();
        void executeTask(void (*fn)(), unsigned long duration);
    private: 
        unsigned long prevMillis;
};
