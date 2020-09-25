class Television {
private:
    unsigned int channel;
    unsigned int sound_intensity;
public:
    Television();
    ~Television();

    void vary_intensity(int quantity = 1);
    void change_channel(unsigned int go_to = 1);
    void show();
};
