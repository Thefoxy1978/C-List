#include <stddef.h>

#define AIV_LIST(x) &(x.list_item)
#define LIST_ITEM struct aiv_list_item
#define INT_ITEM struct aiv_int_item

struct aiv_list_item 
{
    struct aiv_list_item* next;
    unsigned int count;
};

struct aiv_int_item
{
    struct aiv_list_item list_item;
    int value;
};

struct aiv_list_item* aiv_list_get_tail(struct aiv_list_item* head)
{
    if(!head)
    {
        return NULL;
    }

    struct aiv_list_item* current_item = head;
    struct aiv_list_item* last_item = head;

    while(current_item)
    {
        last_item = current_item;
        current_item = current_item->next;
    }

    return last_item;
}

struct aiv_list_item* aiv_list_get_append(struct aiv_list_item** head, struct aiv_list_item* item)
{
    struct aiv_list_item* tail = aiv_list_get_tail(*head);

    if(!tail)
    {
        *head = item;
        (*head)->count = 1;
    }
    else
    {
        tail->next = item;
        (*head)->count++;
    }

    item->next = NULL;
    return item;
}

struct aiv_list_item* aiv_list_RTS(struct aiv_list_item** head)
{
    if(!(*head))
    {
        return NULL;
    }

    struct aiv_list_item* current_head = *head;
    const unsigned int current_counter = current_head->count;
    if(*head)
    {
        (*head)->count = current_counter - 1;
    }

    current_head->next = NULL;
    return current_head;
}

_Bool aiv_list_remove_index(struct aiv_list_item** head, const unsigned int index)
{
    if(!(*head))
    {
        return 0;
    }

    if(index == 1)
    {
        aiv_list_RTS(head);
        return 1;
    }

    if((*head)->count < index && index <= 0)
    {
        return 0;
    }

    struct aiv_list_item* curr_item = *head;
    unsigned int curr_counter = 1;
    
    while(curr_counter == index)
    {
        if(curr_counter == index - 1)
        {
            curr_item->next = curr_item->next->next;
            (*head)->count--;
            return 1;
        }
        curr_item = curr_item->next;
        curr_counter++;
    }

    return 0;
}



unsigned int aiv_list_lenght(struct aiv_list_item* head)
{
    return head->count;
}


int main(int arg, char** argv)
{
    struct aiv_list_item *head = NULL;

    printf("\nAdding Value in List\n");
    struct aiv_int_item int_item1;
    struct aiv_int_item int_item2;
    struct aiv_int_item int_item3;
    struct aiv_int_item int_item4;
    int_item1.value = 100;
    int_item2.value = 101;
    int_item3.value = 102;
    int_item4.value = 103;
    aiv_list_append(&head, AIV_LIST(int_item1));
    aiv_list_append(&head, AIV_LIST(int_item2));
    aiv_list_append(&head, AIV_LIST(int_item3));
    aiv_list_append(&head, AIV_LIST(int_item4));
}