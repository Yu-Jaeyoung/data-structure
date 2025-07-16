import { beforeEach, describe, expect, it } from "bun:test";
import { ArrayList } from "@/list/array-list";

describe("ArrayList", () => {
  describe("when the list is newly created", () => {
    let list: ArrayList<number>;

    beforeEach(() => {
      list = new ArrayList<number>();
    });

    it("should have a size of 0 on initial creation", () => {
      expect(list.sizeOf()).toBe(0);
    });

    it("should return the correct size after adding elements", () => {
      list.add(10);
      list.add(20);

      expect(list.sizeOf()).toBe(2);
    });

    it("should insert an element at a specific index correctly", () => {
      list.add(10);
      list.add(30);

      list.add(1, 20);

      expect(list.sizeOf()).toBe(3);

      expect(list.get(1)).toBe(20);
    });
  });

  describe("when list has pre-existing elements", () => {
    let list: ArrayList<number>;

    beforeEach(() => {
      list = new ArrayList<number>();

      list.add(10);
      list.add(20);
      list.add(30);
    });

    it("should get the element at a specific index", () => {
      expect(list.get(0)).toBe(10);
      expect(list.get(1)).toBe(20);
      expect(list.get(2)).toBe(30);
    });

    it("should remove an element and update the size", () => {
      const removed = list.remove(1);

      expect(removed).toBe(20);
      expect(list.sizeOf()).toBe(2);
    });

    it("should remove first element when remove request index is 0", () => {
      const removed = list.remove(0);

      expect(removed).toBe(10);
      expect(list.sizeOf()).toBe(2);
      expect(list.get(0)).toBe(20);
    });

    describe("when removing the last element", () => {
      let removedElement: number;

      beforeEach(() => {
        removedElement = list.remove(list.sizeOf() - 1);
      });

      it("should return the correct removed element", () => {
        expect(removedElement).toBe(30);
      });

      it("should decrease the size by one", () => {
        expect(list.sizeOf()).toBe(2);
      });
    });
  });

  it("should be empty after removed last element", () => {
    const list = new ArrayList<number>();

    list.add(10);

    list.remove(0);

    expect(list.sizeOf()).toBe(0);
  });

  describe("when attempting to access out of bounds", () => {
    let list: ArrayList<number>;

    beforeEach(() => {
      list = new ArrayList<number>();
    });

    it("should throw an error when removing from an empty list", () => {
      expect(() => list.remove(0)).toThrow("Index out of bounds.");
    });

    it("should throw an error when using a negative index", () => {
      list.add(10);

      expect(() => list.remove(-1)).toThrow("Index out of bounds.");
    });

    it("should throw an error when getting with an out-of-bounds index", () => {
      list.add(10);

      expect(() => list.get(1)).toThrow("Index out of bounds.");
    });
  });
});
