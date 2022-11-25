/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param num int整型
 * @return 无
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
typedef struct Heap {
    int* context;
    int size;
    int capacity;
}Heap;

Heap* heap_max;
Heap* heap_min;

void heap_adjust_up_min(Heap* heap, int child);
void heap_adjust_down_min(Heap* heap, int root);
void heap_adjust_up_max(Heap* heap, int child);
void heap_adjust_down_max(Heap* heap, int root);

void heap_min_push(Heap* heap, int n) {
    if (heap->size == heap->capacity) {
        heap->context = (int*)realloc(heap->context, ((heap->capacity + 1) * 2 - 1) * sizeof(int));
        heap->capacity = (heap->capacity + 1) * 2 - 1;
    }

    heap->context[heap->size] = n;
    heap->size++;
    heap_adjust_up_min(heap, heap->size - 1);
}

void heap_max_push(Heap* heap, int n) {
    if (heap->size == heap->capacity) {
        heap->context = (int*)realloc(heap->context, ((heap->capacity + 1) * 2 - 1) * sizeof(int));
        heap->capacity = (heap->capacity + 1) * 2 - 1;
    }

    heap->context[heap->size] = n;
    heap->size++;
    heap_adjust_up_max(heap, heap->size - 1);
}

void heap_adjust_up_min(Heap* heap, int child) {
    int parent = (child - 1) / 2;
    int temp;

    while (child > 0) {
        if (heap->context[parent] > heap->context[child]) {
            temp = heap->context[parent];
            heap->context[parent] = heap->context[child];
            heap->context[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
        else break;
    }
}

void heap_adjust_up_max(Heap* heap, int child) {
    int parent = (child - 1) / 2;
    int temp;

    while (child > 0) {
        if (heap->context[parent] < heap->context[child]) {
            temp = heap->context[parent];
            heap->context[parent] = heap->context[child];
            heap->context[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
        else break;
    }
}

void heap_pop_min(Heap* heap) {
    int temp = heap->context[0];
    heap->context[0] = heap->context[heap->size - 1];
    heap->context[heap->size - 1] = temp;

    --heap->size;
    heap_adjust_down_min(heap, 0);
}

void heap_pop_max(Heap* heap) {
    int temp = heap->context[0];
    heap->context[0] = heap->context[heap->size - 1];
    heap->context[heap->size - 1] = temp;

    --heap->size;
    heap_adjust_down_max(heap, 0);
}

void heap_adjust_down_min(Heap* heap, int root) {
    int parent = root;
    int child = parent * 2 + 1; // 第一个子节点

    while (child < heap->size) {
        if (child + 1 < heap->size && heap->context[child + 1] < heap->context[child])
            ++child;

        if (heap->context[parent] > heap->context[child]) {
            int temp = heap->context[parent];
            heap->context[parent] = heap->context[child];
            heap->context[child] = temp;

            parent = child;
            child = parent * 2 + 1;
        }
        else break;
    }
}

void heap_adjust_down_max(Heap* heap, int root) {
    int parent = root;
    int child = parent * 2 + 1; // 第一个子节点

    while (child < heap->size) {
        if (child + 1 < heap->size && heap->context[child + 1] > heap->context[child])
            ++child;

        if (heap->context[parent] < heap->context[child]) {
            int temp = heap->context[parent];
            heap->context[parent] = heap->context[child];
            heap->context[child] = temp;

            parent = child;
            child = parent * 2 + 1;
        }
        else break;
    }
}

Heap* init_heap(Heap* heap, int first) {
    heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = 1;
    heap->context = (int*)malloc(sizeof(int));
    heap->context[0] = first;
    return heap;
}

void Insert(int num) {
    // write code here
    if (heap_max == NULL || heap_min == NULL) {
        heap_min = init_heap(heap_min, -100000);
        heap_max = init_heap(heap_max, 100000);
    }

    heap_min_push(heap_min, num);

    if (heap_min->size > heap_max->size) {
        heap_max_push(heap_max, heap_min->context[0]);
        heap_pop_min(heap_min);
    }
    else if (heap_min->size == heap_max->size) {
        if (heap_min->context[0] < heap_max->context[0]) {
            heap_max_push(heap_max, heap_min->context[0]);
            heap_pop_min(heap_min);
            heap_min_push(heap_min, heap_max->context[0]);
            heap_pop_max(heap_max);
        }
    }


}
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param 无
 * @return double浮点型
 */
double GetMedian() {
    // write code here
    double result;
    if (heap_min->size < heap_max->size) result = (double)heap_max->context[0];
    else result = ((double)heap_max->context[0] + (double)heap_min->context[0]) / 2.0;
    return result;
}
