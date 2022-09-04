#include "PCAP.h"

int main(){
    
    std::string  FileNames [3] = {"examples/PPP-config.pcap",  "examples/rtp-norm-transfer.pcap",  "examples/nlmon-big.pcap"};
    for (std::string FileName:FileNames){
        PCAPReader pcapReader{FileName};
        cout << FileName << '\n'<< "packetsCount = "<< pcapReader.packetsCount()<< '\n'<< "payloadSize = "<< pcapReader.payloadSize()<<'\n';
    }

}
