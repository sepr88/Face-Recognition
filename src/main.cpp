#include <iostream>

#include "../include/myvector.h"
#include "../include/ringbuffer.h"
#include "../include/linked_list.h"
#include "../include/binary_tree.h"


int main(int argc, char** argv)
{
    auto bt = binary_tree<int>();

    bt.insert(8);
    bt.insert(3);
    bt.insert(1);
    bt.insert(6);
    bt.insert(4);
    bt.insert(7);
    bt.insert(10);
    bt.insert(13);
    bt.insert(14);

    bt.print();

    std::cout << bt.contains(1) << std::endl;

    return 0;
}


