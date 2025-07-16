import { describe, expect, it } from "bun:test";
import { ArrayList } from "@/list/array-list";

describe("ArrayList", () => {
  it("should have a size of 0 on initial creation", () => {
    const list = new ArrayList<number>();
    expect(list.sizeOf()).toBe(0);
  });

  it("should return the correct size after adding elements", () => {
    const list = new ArrayList<number>();

    list.add(10);
    list.add(20);

    expect(list.sizeOf()).toBe(2);

    list.add(30);

    expect(list.sizeOf()).toBe(3);
  });
});
