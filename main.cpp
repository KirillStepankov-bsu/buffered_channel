#include "buffered_channel.h"

void User1(buffered_channel<int> &channel) {
    channel.Send(10);
    channel.Send(11);
    channel.Send(12);
    channel.Send(13);
    channel.Send(14);
    channel.Send(15);
    channel.Send(16);
    channel.Send(17);
    channel.Send(18);
    channel.Send(19);
}

void User2(buffered_channel<int> &channel) {

    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
    channel.Recv();
}

int main() {
    buffered_channel<int> channel(10);
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(User1, std::ref(channel));
        threads.emplace_back(User2, std::ref(channel));
    }
    for (auto &thread: threads) { thread.join(); }
    return 0;
}
