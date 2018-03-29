//: Playground - noun: a place where people can play

import UIKit

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

class TPostfix
{
    var infix: String
    var postfix: String
    var lenInfix: Int
    
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
        var result: String = ""
        var stack_op: String = ""
        
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
    
    
};

var postfix = TPostfix(val: "a+b+c")
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
postfix.ToPostfix()
print("----");
print("GetPostfix")
print(postfix.GetPostfix())
print("----");
