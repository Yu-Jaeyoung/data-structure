export class Node<T> {
  private _data: T;
  private _next: Node<T> | null;
  private _prev: Node<T> | null;

  constructor(data: T) {
    this._data = data;
    this._next = null;
    this._prev = null;
  }

  get data(): T {
    return this._data;
  }

  get next(): Node<T> | null {
    return this._next;
  }

  get prev(): Node<T> | null {
    return this._prev;
  }

  set data(value: T) {
    this._data = value;
  }

  set next(value: Node<T> | null) {
    this._next = value;
  }

  set prev(value: Node<T> | null) {
    this._prev = value;
  }
}
