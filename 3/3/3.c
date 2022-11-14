struct ListNode p1;
struct ListNode p2;
struct ListNode p3;
struct ListNode phead;
p0 = NULL;
p1 = NULL;
int n = 0;
将k个链表合并到一起
if (listsLen == 1)
{
    return lists[0];
}

for (int i = 0; i(listsLen - 1); i++)
{
    if (lists[i] != NULL)
    {
        p0 = lists[i];
    }
    p1 = lists[i + 1];

    if (p1 != NULL && p0 != NULL)
    {
        while (p0 - next != NULL)
        {
            p0 = p0 - next;
        }
        p0 - next = p1;
    }

}
phead = lists[0];
将链表中的元素排序，采用冒泡法
p0 = phead;
if (p0 == NULL  p0 - next == NULL)
{
    return p0;
}
while (p0 - next != NULL)
{
    p0 = p0 - next;
    n++;
}
p0 = phead;
for (int i = 0; in; i++)
{
    p0 = phead;
    p1 = p0;
    for (int j = 0; j(n - i); j++)
    {
        p2 = p1 - next;
        p3 = p2 - next;
        if (p2 - val  p1 - val)
        {
            p2 - next = p1;
            p1 - next = p3;
            if (p1 == phead)
            {

                phead = p2;
            }
            else
            {
                p0 - next = p2;
            }
            p0 = p2;
        }
        else
        {
            p0 = p1;
        }
        p1 = p0 - next;
    }
}
return phead;
