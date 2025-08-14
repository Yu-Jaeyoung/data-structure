import type { QueueInterface } from "@/queue/common/queue.interface";

export class CircularQueue<T> implements QueueInterface<T> {
  private readonly queue: Array<T | undefined>;
  private tail: number = 0;
  private front: number = 0;
  private readonly capacity: number;
  private size: number = 0;

  constructor(capacity: number) {
    this.queue = new Array<T | undefined>(capacity);
    this.capacity = capacity;
  }

  enqueue(item: T): void {
    if (this.isFull()) {
      throw new Error("Queue is Full");
    }

    this.queue[this.tail] = item;

    this.tail = (this.tail + 1) % this.capacity;

    this.size++;
  }

  dequeue(): T {
    if (this.isEmpty()) {
      throw new Error("Queue is Empty");
    }

    const item: T = this.queue[this.front] as T;

    this.queue[this.front] = undefined;

    this.front = (this.front + 1) % this.capacity;

    this.size--;

    return item;
  }

  peek(): T {
    if (this.isEmpty()) {
      throw new Error("Queue is Empty");
    }

    return this.queue[this.front] as T;
  }

  isEmpty(): boolean {
    return this.size === 0;
  }

  isFull(): boolean {
    return this.size === this.capacity;
  }
}
