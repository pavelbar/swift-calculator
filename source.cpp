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
        var result: String 
        var stack = [String]()
       
        var count: Int = 0
        var i: Int = 0
        var flag: Int = 0 
        
        while i < len 
        {
            let index = infix.index(infix.startIndex, offsetBy: i)
            
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
                    welcome.remove(at: welcome.index(before: welcome.endIndex))
		            		result[count++] = infix[i++];
                }
                
            }
            //--
            i = i + 1
        }
        
        //--
        return postfix;
    }
};

var postfix = TPostfix(s: "1()1")

print(postfix.GetInfix())
print(postfix.GetPostfix())
print(postfix.GetSizeInfix())
postfix.ToPostfix()
