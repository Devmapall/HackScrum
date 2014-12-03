<?hh
setCookie("session",$_POST["sessid"],time()+60*60*24,"/",".mykey.to");
