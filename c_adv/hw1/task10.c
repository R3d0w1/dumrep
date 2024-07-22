/*#include "stdio.h"
#include "stdint.h"
struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
} pack;
void array2struct(int [], struct pack_array *);



int main (void)
{
    int arr[32]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    array2struct(arr,&pack);
    printf("%u\n",pack.array);
    printf("%u\n",pack.count0);
    printf("%u\n",pack.count1);
    return 0;
}
 */
 void array2struct(int arr[], struct pack_array *pack)
 {
    for (int i = 31; i > -1;i--)
    {
        pack->array|=arr[i]<<(31-i);
        pack->count1+=arr[i];
        pack->count0+=arr[i]^1;
    }
 }
 