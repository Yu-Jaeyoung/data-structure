export interface List<T> {
  add (element: T): void;

  add (
    index: number,
    element: T,
  ): void;

  remove (index: number): T;

  get (index: number): T;

  set (
    index: number,
    element: T,
  ): T;

  indexOf (element: T): number;

  size (): number;

  isEmpty (): boolean;

  clear (): void;

  toArray (): T[];
}