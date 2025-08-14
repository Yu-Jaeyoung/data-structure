export interface QueueInterface<T> {
  enqueue(item: T): void;

  dequeue(): T;

  peek(): T;

  isEmpty(): boolean;

  isFull(): boolean;
}
