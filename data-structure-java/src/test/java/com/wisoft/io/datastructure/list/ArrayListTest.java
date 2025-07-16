package com.wisoft.io.datastructure.list;

import com.wisoft.io.datastructure.list.common.ListInterface;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;


class ArrayListTest {

    @Nested
    class SizeAndIsEmpty {
        @Test
        void newListShouldHaveZeroSizeAndBeEmpty() {
            ListInterface<Integer> list = createEmptyList();

            assertEquals(0, list.size());
            assertTrue(list.isEmpty());
        }

        @Test
        void listWithElementsShouldNotBeEmpty() {
            ListInterface<Integer> list = createPreFilledList();

            assertFalse(list.isEmpty());
        }
    }

    @Nested
    class Add {
        @Test
        void addElementShouldIncreaseSize() {
            ListInterface<Integer> list = createEmptyList();

            list.add(10);
            assertEquals(1, list.size());

            list.add(20);
            assertEquals(2, list.size());
        }

        @Test
        void addElementToSpecificIndexShouldIncreaseSize() {
            ListInterface<Integer> list = createPreFilledList();

            list.add(1, 99);

            assertEquals(4, list.size());
            assertEquals(99, list.get(1));
            assertEquals(20, list.get(2));
        }
    }

    @Nested
    class Get {
        @Test
        void getElementShouldReturnCorrectValue() {
            ListInterface<Integer> list = createPreFilledList();

            assertEquals(10, list.get(0));
            assertEquals(20, list.get(1));
            assertEquals(30, list.get(2));
        }
    }

    @Nested
    class Set {
        @Test
        void setElementShouldChangeValueAtIndex() {
            ListInterface<Integer> list = createPreFilledList();

            list.set(1, 99);

            assertEquals(99, list.get(1));
            assertEquals(3, list.size()); // 크기는 변하지 않음
        }
    }

    @Nested
    class Remove {
        @Test
        void removeElementShouldDecreaseSizeAndReturnValue() {
            ListInterface<Integer> list = createPreFilledList();

            Integer removedValue = list.remove(1);

            assertEquals(20, removedValue);
            assertEquals(2, list.size());
            assertEquals(30, list.get(1));
        }
    }

    @Nested
    class IndexOf {
        @Test
        void indexOfShouldReturnCorrectIndexForExistingElement() {
            ListInterface<Integer> list = createPreFilledList();

            assertEquals(1, list.indexOf(20));
        }

        @Test
        void indexOfShouldReturnMinusOneForNonExistingElement() {
            ListInterface<Integer> list = createPreFilledList();

            assertEquals(-1, list.indexOf(99));
        }

        @Test
        void indexOfShouldReturnMinusOneWhenListIsEmpty() {
            ListInterface<Integer> list = createEmptyList();

            assertEquals(-1, list.indexOf(10));
        }

        @Test
        void indexOfShouldReturnFirstIndexWhenDuplicatesExist() {
            ListInterface<Integer> list = createEmptyList();

            list.add(10);
            list.add(20);
            list.add(10);

            assertEquals(0, list.indexOf(10));
        }
    }

    @Nested
    class Clear {
        @Test
        void clearOnPreFilledListShouldResultInEmptyList() {
            ListInterface<Integer> list = createPreFilledList();

            list.clear();

            assertTrue(list.isEmpty());
            assertEquals(0, list.size());
        }

        @Test
        void clearOnEmptyListShouldDoNothing() {
            ListInterface<Integer> list = createEmptyList();

            assertDoesNotThrow(list::clear);
            assertTrue(list.isEmpty());
        }
    }

    @Nested
    class OutOfBoundsAccess {
        @Test
        void getWithNegativeIndexShouldThrowException() {
            ListInterface<Integer> list = createPreFilledList();

            assertThrows(IndexOutOfBoundsException.class, () -> list.get(-1));
        }

        @Test
        void getWithIndexEqualToSizeShouldThrowException() {
            ListInterface<Integer> list = createPreFilledList();

            assertThrows(IndexOutOfBoundsException.class, () -> list.get(3));
        }

        @Test
        void removeFromEmptyListShouldThrowException() {
            ListInterface<Integer> list = createEmptyList();

            assertThrows(IndexOutOfBoundsException.class, () -> list.remove(0));
        }
    }

    private ListInterface<Integer> createEmptyList() {
        return new ArrayList<>();
    }

    private ListInterface<Integer> createPreFilledList() {
        ListInterface<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);

        return list;
    }
}