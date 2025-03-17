class BuiltinLED {
    public:
        BuiltinLED(int pin);

        void blink(int loop, int duration);
        void steady();
    private: 
        const int _pin;
};