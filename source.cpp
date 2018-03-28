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
            
            if (infix[index]  != "+" && infix[index]  != "-" && infix[index] != "*" && infix[index]  != "/" && infix[index] != ")")
            {
                print("not plus/minus/mult");
            }
            else
            {
                print("have plus/minus/mult");
            }
            //--
            i = i + 1
        }
        
        //--
        return postfix;
    }
};

var postfix = TPostfix(s: "+2-2*")

print(postfix.GetInfix())
print(postfix.GetPostfix())
print(postfix.GetSizeInfix())
postfix.ToPostfix()
