import { describe, expect, it } from "bun:test";
import { DoublyLinkedList } from "@/list/doubly-linked-list";

const createEmptyList = () => new DoublyLinkedList<number>();

const createPreFilledList = () => {
  const list = new DoublyLinkedList<number>();

  list.add(10);
  list.add(20);
  list.add(30);

  return list;
};

describe("DoublyLinkedList", () => {
  describe("when the list is newly created", () => {
    it("should have a size of 0 on initial creation", () => {
      const list = createEmptyList();

      expect(list.sizeOf()).toBe(0);
    });

    it("should return the correct size after adding elements", () => {
      const list = createEmptyList();

      list.add(10);
      list.add(20);

      expect(list.sizeOf()).toBe(2);
    });

    it("should insert an element at a specific index correctly", () => {
      const list = createEmptyList();

      list.add(10);
      list.add(30);

      list.add(1, 20);

      expect(list.sizeOf()).toBe(3);

      expect(list.get(1)).toBe(20);
    });

    it("should be empty after an element is added and then removed", () => {
      const list = createEmptyList();

      list.add(10);
      list.remove(0);

      expect(list.isEmpty()).toBe(true);
    });
  });

  describe("when list has pre-existing elements", () => {
    it("should get the element at a specific index", () => {
      const list = createPreFilledList();

      expect(list.get(0)).toBe(10);
      expect(list.get(1)).toBe(20);
      expect(list.get(2)).toBe(30);
    });

    it("should remove an element and update the size", () => {
      const list = createPreFilledList();

      const removed = list.remove(1);

      expect(removed).toBe(20);
      expect(list.sizeOf()).toBe(2);
    });

    it("should correctly update the list when removing the first element", () => {
      const list = createPreFilledList();

      const removed = list.remove(0);

      expect(removed).toBe(10);
      expect(list.get(0)).toBe(20);
      expect(list.sizeOf()).toBe(2);
    });

    it("should set the element at a specific index", () => {
      const list = createPreFilledList();

      list.set(1, 99);

      expect(list.get(1)).toBe(99);
      expect(list.get(0)).toBe(10);
    });

    describe("when removing the last element", () => {
      it("should return the correct removed element", () => {
        const list = createPreFilledList();

        const removedElement = list.remove(list.sizeOf() - 1);

        expect(removedElement).toBe(30);
      });

      it("should decrease the size by one", () => {
        const list = createPreFilledList();

        list.remove(list.sizeOf() - 1);

        expect(list.sizeOf()).toBe(2);
      });
    });
  });

  describe("when attempting to access out of bounds", () => {
    it("should throw an error when removing from an empty list", () => {
      const list = createEmptyList();

      expect(() => list.remove(0)).toThrow("Index out of bounds.");
    });

    it("should throw an error when using a negative index", () => {
      const list = createPreFilledList();

      expect(() => list.remove(-1)).toThrow("Index out of bounds.");
    });

    it("should throw an error when getting with an out-of-bounds index on a non-empty list", () => {
      const list = createEmptyList();

      list.add(10);

      expect(() => list.get(1)).toThrow("Index out of bounds.");
    });

    it("should throw an error when setting on an empty list", () => {
      const list = createEmptyList();

      expect(() => list.set(0, 10)).toThrow("Index out of bounds.");
    });

    it("should throw an error when setting with a negative index", () => {
      const list = createPreFilledList();

      expect(() => list.set(-1, 99)).toThrow("Index out of bounds.");
    });
  });

  describe("isEmpty", () => {
    it("should return true for a newly created list", () => {
      const list = createEmptyList();
      expect(list.isEmpty()).toBe(true);
    });

    it("should return false for a list with elements", () => {
      const list = createPreFilledList();
      expect(list.isEmpty()).toBe(false);
    });
  });

  describe("indexOf", () => {
    it("should return the correct index of the list", () => {
      const list = createPreFilledList();

      expect(list.indexOf(10)).toBe(0);
    });

    it("should return -1 with un-exist element", () => {
      const list = createPreFilledList();

      expect(list.indexOf(40)).toBe(-1);
    });

    it("should return -1 when list is empty", () => {
      const list = createEmptyList();

      expect(list.indexOf(10)).toBe(-1);
    });

    it("should return the first index when duplicates exist", () => {
      const list = createEmptyList();

      list.add(10);
      list.add(20);
      list.add(10);

      expect(list.indexOf(10)).toBe(0);
    });
  });

  describe("clear", () => {
    it("should clear the pre filled list", () => {
      const list = createPreFilledList();

      list.clear();

      expect(list.isEmpty()).toBe(true);
      expect(list.sizeOf()).toBe(0);
    });

    it("should not throw an error when clearing an empty list", () => {
      const list = createEmptyList();

      list.clear();

      expect(list.isEmpty()).toBe(true);
      expect(list.sizeOf()).toBe(0);
    });
  });
});
