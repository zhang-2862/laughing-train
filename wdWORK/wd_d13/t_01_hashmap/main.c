//实现哈希表的动态扩容
#include "HashMap.h"

int main(void) {
    HashMap* map=hashmap_create();

    hashmap_put(map, "i am iron man 1", "no.1");
    hashmap_put(map, "i am iron man 2", "no.2");
    hashmap_put(map, "i am iron man 3", "no.3");
    hashmap_put(map, "i am iron man 4", "no.4");
    hashmap_put(map, "i am iron man 5", "no.5");
    hashmap_put(map, "i am iron man 6", "no.6");
    hashmap_put(map, "i am iron man 7", "no.7");
    hashmap_put(map, "i am iron man 8", "no.8");

    hashmap_put(map, "i am spider man", "no.001");
    return 0;
}