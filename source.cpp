//print("Hello World! :-)");

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
    
    func Priority(val: String) -> Int
	{
		if ((val[0] == "*") || (val[0] == "/")) 
		{
		    return 2;
		}
	
		if ((val[0] == "+") || (val[0] == "-")) 
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
            let index = infix.index(infix.startIndex, offsetBy: i)
         //--1--
             if (infix[index] != "(" && infix[index] != ")" && infix[index] != "+" && infix[index] != "-" && infix[index] != "*" && infix[index] != "/" )
             {
                result.insert(infix[index], at: result.endIndex) 
             }
        //--2--
	    	if (infix[index] == "(")
	    	{
	        	stack_op.insert(infix[index], at: stack_op.endIndex) 
	    	}
	    //--3--  
	    if (infix[index] == ")")
	    {

	    }
         //--
         }
         return postfix;
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
postfix.ToPostfix()

/*
//print("Hello World! :-)");

class TPostfix
{
  var infix: String
  var postfix: String

  init(s: String) 
  {
    self.infix = s
    self.postfix = s
  }
  
  func GetInfix() -> String 
  {
    return infix
  }
  
    func GetPostfix() -> String 
  {
    return postfix
  }
    
    func GetSizeInfix() -> Int
    {
        return infix.characters.count
    }
    
    func ToPostfix() -> String
    {
        var len: Int = GetSizeInfix()
        var result: String  = ""
        var stack = [String]()
       
        var count: Int = 0
        var i: Int = 0
        var flag: Int = 0 
        
        while i < len 
        {
            let index = infix.index(infix.startIndex, offsetBy: i)
            let indexInc = infix.index(infix.startIndex, offsetBy: i+1)
            
            if (infix[index] != "+" && infix[index] != "-" && infix[index] != "*" && infix[index] != "/" && infix[index] != "(" && infix[index] != ")" )
            {
                flag = 0
                while (infix[index] != "+" && infix[index] != "-" && infix[index] != "*" && infix[index] != "/" && infix[index] != "(" && infix[index] != ")" )
                {
                    if ((infix[index] >= "a" && infix[index] <= "z") || (infix[index] >= "A" && infix[index] <= "Z")) 
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1
                    }
                    result.insert(infix[indexInc], at: result.endIndex)
                }
                if( flag==1)
                {
                    result.insert(" ", at: result.endIndex)
                }
                
            }
            //--
            i = i + 1
        }
        
        //--
        return postfix;
    }
};

var postfix = TPostfix(s: "22")

print(postfix.GetInfix())
print(postfix.GetPostfix())
print(postfix.GetSizeInfix())
postfix.ToPostfix()
*/
