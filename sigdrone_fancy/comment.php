<?php include 'settings.php'?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Quadrotor Videography</title>
<link href="css/common.css" rel="stylesheet" type="text/css" />



 <SCRIPT LANGUAGE=JavaScript>

function formCheck()
{
     if(document.formfinal.Feelings.value.length>0)
       return true;
    else
  {
    alert("Please provide all the information above, thank you!\n Unfinished！");
    return false;
  }
}

</SCRIPT>


</head>
<body >
<div class="top">
 <div style="with:1000px; margin:auto;"><img style=" margin-left:600px;" src="img/white.png" width="355" height="215" /></div>
</div>

<?php include $User_Answers = (string)$_POST["User_Answers"];?>

<div class="main">
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p style=" font-size:36px;  color:#333;"> 

  

Any other feelings or thoughts,</p>
  <p style=" font-size:36px;  color:#333;"> please comment below: </p>
  <p>&nbsp;</p>
  <p style=" font-size:18px; line-height:26px; color:#999;">&nbsp;</p>
</div>
<div class="main"><table width="100%" border="0" align="center" cellpadding="0">
<form name="formfinal" method="post" action="result.php" onsubmit="return formCheck()">
  <tr>
    <td>
      <p>
        <input type="text" name="Feelings" style="width:680px; line-height:39px; height:300px; border:#E0E0E0 1px solid; font-size:18px; color:#999; margin:5px; text-align:center; name="Feelings1" id="textarea" cols="100" rows="8" onkeyup="value=value.replace(/[^\w\.\ \,\:]/ig,'')">
      </p>
    </td>
    <td><p><input type="image" src="img/submitc.png" onmousemove="this.src='img/submitc.png'" method="post" onmouseout="this.src='img/submitc.png'" width="182" height="171"  /></p></td>
    <input type="hidden" name="User_Answers" value="<?php echo($User_Answers);?>">
    </tr>
    </form>
</table>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
</div>
<div style=" background:url(img/comments.jpg) repeat-x; height:195px;"></div>
</body>
</html>
