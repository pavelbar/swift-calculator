//
//  Created by PavelBaranov on 29.03.2018.
//  Copyright © 2018 Admin. All rights reserved.
//
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
    var result: Double = 0;
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
    
    //
    //  Created by PavelBaranov on 29.03.2018.
    //  Copyright © 2018 Admin. All rights reserved.
    //
    
    
    func Calculate(valA: Double, valB: Double) -> Double
    {
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
                else if postfix[i] == "a"
                {
                    stack.append(valA)
                }
                else if postfix[i] == "b"
                {
                    stack.append(valB)
                }
                
            }
            else
                //--b--
            {
                if (postfix[i] == "+")
                {
                    let tmp1: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    let tmp11: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    stack.append(tmp11 + tmp1)
                }
                if (postfix[i] == "-")
                {
                    let tmp1: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    let tmp11: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    stack.append(tmp11 - tmp1)
                }
                if (postfix[i] == "/")
                {
                    let tmp1: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    let tmp11: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    stack.append(tmp11 / tmp1)
                }
                if (postfix[i] == "*")
                {
                    let tmp1: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    let tmp11: Double = stack[stack.count - 1]
                    stack.removeLast()
                    
                    stack.append(tmp11 * tmp1)
                }
            }
        }
        return stack[stack.count - 1]
        
    }
    
};


//
//  Created by PavelBaranov on 29.03.2018.
//  Copyright © 2018 Admin. All rights reserved.
//


import UIKit

class ViewController: UIViewController {
    
    var s: String = ""
    var onClickCalck: Bool = false
    
    @IBOutlet weak var fieldB: UITextField!
    
    @IBOutlet weak var fieldA: UITextField!
    
    @IBOutlet weak var labelPostfix: UILabel!
    
    @IBOutlet weak var labelResult: UILabel!
    
    @IBAction func numbers(_ sender: UIButton)
    {
        if sender.tag == 1{
            s = s + "a"
        }
        if sender.tag == 2{
            s = s + "b"
        }
        if sender.tag == 3{
            if s.count != 0
            {
                s.remove(at: s.index(before: s.endIndex))
            }
        }
        if sender.tag == 4{
            s = s + "/"
        }
        if sender.tag == 5{
            s = s + "0"
        }
        if sender.tag == 6{
            s = s + "("
        }
        if sender.tag == 7{
            s = s + ")"
        }
        if sender.tag == 8{
            s = s + "*"
        }
        if sender.tag == 9{
            s = s + "1"
        }
        if sender.tag == 10{
            s = s + "2"
        }
        if sender.tag == 11{
            s = s + "3"
        }
        if sender.tag == 12{
            s = s + "-"
        }
        if sender.tag == 13{
            s = s + "4"
        }
        if sender.tag == 14{
            s = s + "5"
        }
        if sender.tag == 15{
            s = s + "6"
        }
        if sender.tag == 16{
            s = s + "+"
        }
        if sender.tag == 17{
            s = s + "7"
        }
        if sender.tag == 18{
            s = s + "8"
        }
        if sender.tag == 19{
            s = s + "9"
        }
        if sender.tag == 20{
            if s.count != 0
            {
                onClickCalck = true
                let postfix = TPostfix(val: s)
                labelPostfix.text = "postfix: " + postfix.ToPostfix()
                
                let valA: String!
                let valB: String!
                valA = fieldA.text
                valB = fieldB.text
                labelResult.text = String(postfix.Calculate(valA: Double(valA)!, valB: Double(valB)!))
            }
        }
        if onClickCalck == false
        {
            if s.count == 0
            {
                labelResult.text = "_"
            }
            else
            {
                labelResult.text = s
            }
        }
        onClickCalck = false
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}


