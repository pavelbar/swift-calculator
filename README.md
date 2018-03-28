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
};
