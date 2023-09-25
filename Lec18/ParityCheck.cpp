#include <iostream>
#include <queue>
using namespace std;

struct Packet {
    int priority;
    string data;

    bool operator>(const Packet& other) const {
        return priority > other.priority;
    }
};

int main() {
    int capacity;
    cin >> capacity;

    int numPackets;
    cin >> numPackets;

    priority_queue<Packet, vector<Packet>, greater<Packet>> packetQueue;

    cout << "Processing packets based on priority:" << endl;

    for (int i = 0; i < numPackets; i++) {
        int priority;
        cin >> priority;

        string data;
        cin.ignore(); 
        getline(cin, data);

        Packet packet = {priority, data};
        packetQueue.push(packet);
    }

    while (!packetQueue.empty()) {
        Packet packet = packetQueue.top();
        packetQueue.pop();

        cout << "Processing packet with priority " << packet.priority << " and data: " << packet.data << endl;
    }

    return 0;
}
