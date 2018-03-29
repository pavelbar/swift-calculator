//print("Hello World! :-)");


extension String {
    subscript (i: Int) -> Character {
        return Array(self.characters)[i]
    }

    subscript (r: CountableClosedRange<Int>) -> String {
        return String(Array(self.characters)[r])
    }

    subscript (r: CountableRange<Int>) -> String {
        return self[r.lowerBound...r.upperBound-1]
    }
}

func atoi(str: Character) -> Double
{
var result:
    Double = 0;
    if (str == "1")
    {
        result = 1;
    }

    if (str == "2")
    {
        result = 2;
    }

    if (str == "3")
    {
        result = 3;
    }

    if (str == "4")
    {
        result = 4;
    }

    if (str == "5")
    {
        result = 5;
    }

    if (str == "6")
    {
        result = 6;
    }

    if (str == "7")
    {
        result = 7;
    }
    if (str == "8")
    {
        result = 8;
    }
    if (str == "9")
    {
        result = 9;
    }
    //--
    return result
}

class TPostfix
{
var infix:
    String
var postfix:
    String
var lenInfix:
    Int

    init(val: String)
    {
        self.infix = val
                     self.postfix = val
                                    self.lenInfix = infix.characters.count
    }

    func GetInfix() -> String   {return infix}

    func GetPostfix() -> String {return postfix}

    func GetSizeInfix() -> Int  {return lenInfix}

    func Priority(val: Character) -> Int
    {
        if ((val == "*") || (val == "/"))
        {
            return 2;
        }

        if ((val == "+") || (val == "-"))
        {
            return 1;
        }

        return -7;
    }

    func ToPostfix() -> String
    {
var result:
        String = ""
var stack_op:
        String = ""

        for i in 0...self.lenInfix - 1
    {
        //--1--
        if (infix[i] != "(" && infix[i] != ")" && infix[i] != "+" && infix[i] != "-" && infix[i] != "*" && infix[i] != "/" )
            {
                result.insert(infix[i], at: result.endIndex)
            }
            //--2--
            if (infix[i] == "(")
            {
                stack_op.insert(infix[i], at: stack_op.endIndex)//Push
            }
            //--3--
            if (infix[i] == ")")
            {
                while (stack_op[stack_op.characters.count - 1] != "(")//Top
                {
                    result.insert( stack_op[stack_op.characters.count - 1], at: result.endIndex)//Pop1
                    stack_op.remove(at: stack_op.index(before: stack_op.endIndex))//Pop2
                }
                stack_op.remove(at: stack_op.index(before: stack_op.endIndex))//Pop2
            }
            //-----
            if ((infix[i] == "+") || (infix[i] == "-") || (infix[i] == "*") || (infix[i] == "/"))
            {
                //--a--
                if (stack_op.characters.count == 0 || stack_op[stack_op.characters.count - 1] == "(")
                {
                    stack_op.insert(infix[i], at: stack_op.endIndex)//Push
                }
                //--b--
                else if (Priority(val: infix[i]) > Priority(val: stack_op[stack_op.characters.count - 1]))
                {
                    stack_op.insert(infix[i], at: stack_op.endIndex)//Push
                }
                //--c--
                else
                {
                    while (stack_op.characters.count != 0 && Priority(val: infix[i]) <= Priority(val: stack_op[stack_op.characters.count - 1]))
                    {
                        result.insert( stack_op[stack_op.characters.count - 1], at: result.endIndex)//Pop1
                        stack_op.remove(at: stack_op.index(before: stack_op.endIndex))//Pop2
                    }
                    stack_op.insert(infix[i], at: stack_op.endIndex)//Push
                    //-----
                }
            }
            //--
        }
        //--4--
        while (stack_op.characters.count != 0)//пока
        {

            result.insert( stack_op[stack_op.characters.count - 1], at: result.endIndex)//Pop1
            stack_op.remove(at: stack_op.index(before: stack_op.endIndex))//Pop2
        }
        //-----
        postfix = result;
        return postfix;
    }

//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------


    func Calculate() -> Double
    {
        //https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BF%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C#.D0.9E.D0.B1.D1.89.D0.B8.D0.B9_.D0.BF.D0.BE.D1.80.D1.8F.D0.B4.D0.BE.D0.BA
        //Алгоритм:
        //1. Обработка входного символа
        //    a) Если на вход подан операнд, он помещается на вершину стека.
        //    b) Если на вход подан знак операции, то соответствующая операция выполняется над требуемым количеством значений,
        //    извлечённых из стека, взятых в порядке добавления.Результат выполненной операции кладётся на вершину стека.
        //2. Если входной набор символов обработан не полностью, перейти к шагу 1.
        //3. После полной обработки входного набора символов результат вычисления выражения лежит на вершине стека.

        var stack = [Double]()

        for i in 0...postfix.characters.count - 1
    {
        //--a--
        if (postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/")
            {

                if ((postfix[i] == "0") || (postfix[i] == "1") || (postfix[i] == "2") || (postfix[i] == "3") || (postfix[i] == "4") || (postfix[i] == "5") || (postfix[i] == "6") || (postfix[i] == "7") || (postfix[i] == "8") || (postfix[i] == "9") )
                {
                    stack.append(atoi(str: postfix[i])) // преобразовать символы к типу double
                }
                else
                {
                    print(postfix[i], "=");
                    let k = Double(readLine(strippingNewline: true)!)!
                            stack.append(k)
                }

            }
            else
                //--b--
            {
                if (postfix[i] == "+")
                {
let tmp1:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

let tmp11:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

                    stack.append(tmp11 + tmp1)
                }
                if (postfix[i] == "-")
                {
let tmp1:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

let tmp11:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

                    stack.append(tmp11 - tmp1)
                }
                if (postfix[i] == "/")
                {
let tmp1:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

let tmp11:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

                    stack.append(tmp11 / tmp1)
                }
                if (postfix[i] == "*")
                {
let tmp1:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

let tmp11:
                    Double = stack[stack.count - 1]
                    stack.removeLast()

                    stack.append(tmp11 * tmp1)
                }
            }
        }
        return stack[stack.count - 1]

    }

};

var postfix = TPostfix(val: "2+2+2")
              print("----");
print("prior+")
print(postfix.Priority(val: "+"))
print("----");
print("prior*")
print(postfix.Priority(val: "*"))
print("----");
print("GetInfix")
print(postfix.GetInfix())
print("----");
print("GetPostfix")
print(postfix.GetPostfix())
print("----");
print("GetSizeInfix")
print(postfix.GetSizeInfix())
print("----");
print("ToPostfix")
print(postfix.ToPostfix())
print("----");
print("Calculate=")
print(postfix.Calculate())
