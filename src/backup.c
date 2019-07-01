else if(token->str[0]=='('){
  IntegerToken * intToken;
  freeToken(token);
  intToken = (IntegerToken *)getToken(tokenizer);
  if(token->str[0]=='X' || token->str[0]=='Y'){
    freeToken(token);
    intToken = (IntegerToken *)getToken(tokenizer);
    if(token)
  }
}
