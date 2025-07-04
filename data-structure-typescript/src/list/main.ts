import { ArrayList } from "./array-list";

const list = new ArrayList<number>();

list.add(0, 10);
list.add(0, 20);
list.add(1, 30);

list.printAll();

list.remove(1);

list.printAll();

console.log(list.get(0));

list.set(0, 50);
list.printAll();

console.log(`isEmpty: ${ list.isEmpty() }`);
console.log(`indexOf: ${ list.indexOf(50) }`);
console.log(`size: ${ list.size() }`);

list.clear();
console.log(`isEmpty: ${ list.isEmpty() }`);
list.printAll();