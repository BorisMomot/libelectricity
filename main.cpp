#include <iostream>
#include "GRU.h"
using namespace std;

int main() {
    GRU gru1;
    Source gen1(2000,100);
    Consumer consumer1(1500);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);

//    cout<<"DEBUG0"<<endl;

    gen1.startSource();
    gen1.setU(220);
    gen1.setF(50);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    cout<<"IsConnected"<<gen1.getIsConnected()<<endl;
    cout<<"CurrentSourceVoltage"<<gen1.getU()<<endl;
    gru1.calculate(1);
    cout<<"GetCurrentIa"<<gen1.getIa()<<endl;
    cout<<"Gen1 get current P = "<<gen1.getP()<<endl;
    cout<<"SomeConsumer get current P = "<<consumer1.getP()<<endl;
    return 0;
}