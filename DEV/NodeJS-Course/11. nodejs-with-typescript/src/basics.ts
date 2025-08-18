console.log("Hello Node js from typescript");

//basic types

let isDone: Boolean = false;

let num: number = 100;

let str: string = "Sangam";

let list: number[] = [1, 2, 3];
let products: Array<string> = ["product 1", "product 2", "product 3"];

let randomVal: any = 4;

randomVal = "sangam";
randomVal = true;
randomVal = [];

let xyz: undefined = undefined;
let yz: null = null;

enum Color {
  Red,
  Green,
  Blue,
}

let d: Color = Color.Green;

//tuple

let abc: [string, number] = ["hi", 400];

//interfaces, types

interface User {
  name: String;
  id: number;
  email?: string; //optional
  readonly createdAt: Date;
}

const user: User = {
  name: "Sangam",
  id: 1,
  createdAt: new Date(),
  email: "abc@gmail.com",
};

type Product = {
  title: string;
  price: number;
};

const product1: Product = {
  title: "Product 1",
  price: 200,
};

//functions with type annotations

function multiply(a: number, b: number): number {
  return a * b;
}

const add = (num1: number, num2: number): number => {
  return num1 + num2;
};

function greet(name: string, greeting?: string): string {
  return `${name} ${greeting}`;
}

console.log(greet("sangam", "hello"));
