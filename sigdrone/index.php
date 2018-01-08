
<!DOCTYPE HTML>
<html lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html"; charset="utf-8"/>
  <title>Aerial Video</title>
  
  <link rel="stylesheet" href="style/style.css">
  <link rel="stylesheet" href="style/common.css">

  <link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon">
  
  <script src="style/jquery.min.js"></script> 
</head>

<body>
  <div class="content index-page">  
    <div class="top">
      <p style="font-size:35px;margin:20px;margin-top:45px;margin-left:40px;margin-right:40px"> 
        <b>
        A User Study on Aerial Video
        </b>
      </p>
      <p style="font-size:8px; margin:18px">&nbsp;</p>      
      <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
        In the following, you will be shown a few groups of Aerial Videos. In each group, there are two videos about the same scene.
      </p>
      
      <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
        For each scene, you will be asked 3 questions regarding the quality of these videos.
      </p>
      
      <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
        The study evaluates 2 different secnes and it will take about 15 minutes to complete.
      </p>
      
      <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
        Any information you provide will not be used for any other purposes and will not be sold, rented, leased or forwarded to any third party.
      </p>

      <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
        Thanks.
      </p>

    </div>
    <p style="font-size:20px;margin:18px;margin-left:80px;margin-right:80px;text-align:justify;line-height:1.5">
    </p>


    <center>
      <form name="form_info" method="post" action="vote.php">
    <center>
            <table>
            <tr>
              <td>Gender :</td>
              <td colspan="4"><input name = "Usr_Info_Gender" type="text" size="30"></td>
            </tr>
            <tr>
              <td>Age :</td>
              <td colspan="4"><input name = "Usr_Info_Age"  type="text" size="30"></td>
            </tr>
            <tr>
              <td>Drone Using Histroy :</td>
              <td colspan="4"><input name = "Usr_Info_Pilot"  type="text" size="30"></td>
            </tr>
            </table>
    </center>  
        <p style="font-size:20px; margin:8px">&nbsp;</p>      
      <input type="image" src="img/go.png" onmousemove="this.src='img/go_on.png'" method="post" onmouseout="this.src='img/go.png'" width="182" height="171" />

    </form>
    </center>

  </div>
</body>
</html>