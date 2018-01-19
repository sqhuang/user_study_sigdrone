<!-- for drone project -->
<?php include 'settings.php'?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Voting</title>
<link href="css/common.css" rel="stylesheet" type="text/css" />

 <SCRIPT LANGUAGE=JavaScript>

function formCheck()
{
    var flag1 = false;
  var flag2 = false;
  var flag3 = false;
  var flag4 = false;
  var flag5 = false;

  for(i=0;i<document.form_voting.Which_is_better_one.length;i++)
　　{
     　　if(document.form_voting.Which_is_better_one[i].checked)
       　　flag1 = true;
　　}
    for(i=0;i<document.form_voting.Which_is_better_two.length;i++)
　　{
     　　if(document.form_voting.Which_is_better_two[i].checked)
       　　flag2 = true;
　　}
    for(i=0;i<document.form_voting.Which_is_better_three.length;i++)
　　{
     　　if(document.form_voting.Which_is_better_three[i].checked)
       　　flag3 = true;
　　}
    for(i=0;i<document.form_voting.Which_is_better_four.length;i++)
　　{
     　　if(document.form_voting.Which_is_better_four[i].checked)
       　　flag4 = true;
　　}
    for(i=0;i<document.form_voting.Which_is_better_five.length;i++)
　　{
     　　if(document.form_voting.Which_is_better_five[i].checked)
       　　flag5 = true;
　　}

    if(!(flag1 && flag2 && flag3 && flag4 && flag5))
  {
    alert("Please answer all questions, thank you!\n Unfinished！");
    return false;
  }
  else
  {
    return true;
  }
}
</SCRIPT>

</head>
<body>

    <?php include 'data.php';?>
    <?php include 

  $Usr_Info_Gender = (string)$_POST["Usr_Info_Gender"];
  $Usr_Info_Age = (string)$_POST["Usr_Info_Age"];
  $Usr_Info_Pilot = (string)$_POST["Usr_Info_Pilot"];

  $Is_new_voting = (string)$_POST["Is_new_voting"];
  $Samples_ID_Sequence = $_POST["Samples_ID_Sequence"];
    $User_Answers = (string)$_POST["User_Answers"];
  $Samples_ID_Sequence_array = array();

  $First_video_name = $_POST["First_video_name"];
  $Second_video_name = $_POST["Second_video_name"];
  $NumHasDid = (int)$_POST["NumHasDid"];
  $Which_is_better_one = $_POST["Which_is_better_one"];
  $Which_is_better_two = $_POST["Which_is_better_two"];
  $Which_is_better_three = $_POST["Which_is_better_three"];
  $Which_is_better_four = $_POST["Which_is_better_four"];
  $Which_is_better_five = $_POST["Which_is_better_five"];

  function microtime_float()
    {
    list($usec, $sec) = explode(" ", microtime());
    return ((float)$usec + (float)$sec);
  }

    if($Which_is_better_one != "" )
  {
    $User_Answers = $User_Answers."\n".$Which_is_better_one;
    $User_Answers = $User_Answers."|\t\t\t".$Which_is_better_two;
    $User_Answers = $User_Answers."|\t\t\t".$Which_is_better_three;
    $User_Answers = $User_Answers."|\t\t\t".$Which_is_better_four;
    $User_Answers = $User_Answers."|\t\t\t".$Which_is_better_five;

    $starttime = $_POST["Starttime"];
    $endtime = microtime_float(); 
    $runtime = number_format($endtime - (float)$starttime, 4).'s';  
    
    $User_Answers = $User_Answers."|\t\t\t time: ".$runtime;
  }

  if (!($Is_new_voting=="false"))
  {
    $Is_new_voting = "true";
    $Samples_ID_Sequence_array = range(1,count($Video_names_need_to_be_compared_true));
    shuffle($Samples_ID_Sequence_array);
    

    $Samples_ID_Sequence = (string)$Samples_ID_Sequence_array[0];
    for ($i = 1; $i < count($Samples_ID_Sequence_array); $i++)
    {
      $Samples_ID_Sequence = $Samples_ID_Sequence." ".$Samples_ID_Sequence_array[$i];
    }
  }
  else
  {
    $Samples_ID_Sequence_array  = explode(" ", $Samples_ID_Sequence);
  }

  $Real_sample_ID = $Samples_ID_Sequence_array[$Sample_ID - 1];

if ($NumHasDid < count($Video_names_need_to_be_compared_true) )
  {

      $Starttime = microtime_float(); 
  
    $Sample_ID = (int)$Samples_ID_Sequence_array[$NumHasDid];
    $First_video_name = $Video_names_need_to_be_compared_true[$Sample_ID][0];
    $Second_video_name = $Video_names_need_to_be_compared_true[$Sample_ID][1];
    // $Size_top = $Video_names_need_to_be_compared_true[$Sample_ID][2];
    // $Size_simplified = $Video_names_need_to_be_compared_true[$Sample_ID][3];
    $Array_tmp = explode(" ", $First_video_name);
    $Real_sample_ID = (int) $Array_tmp[0];
    

    $Rand_num_for_select_to_display = rand(0,5);

    if ($Rand_num_for_select_to_display > 2)
    {
      $Video_name_tmp = $First_video_name; 
      $First_video_name = $Second_video_name;
      $Second_video_name = $Video_name_tmp;
    }
    $NumHasDid+=1;
  

    ?>


<div class="top">
 <div style="with:1000px; margin:auto;"><img style=" margin-left:600px;" src="img/white.png" width="355" height="215" /></div>
</div>
<div style="width:1075px; margin:auto;">
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <table width="100%" border="0" align="center" cellpadding="0">
    <tr>
      <td width="43%"><img src="videos/<?php echo($Real_sample_ID."/".($Real_sample_ID).".jpg"); ?>"" width="420" height="234" /></td>
      <td width="3%">&nbsp;</td>
      <td width="54%"><p style=" font-size:36px;  color:#333;">We value your opinions!</p>
        <p>&nbsp;</p>
        <p style=" font-size:18px; line-height:26px; color:#999;">  
        <strong>-</strong> All areas marked in red in the map (left) are landmarks we want to explore.</p>
        <p style=" font-size:18px; line-height:26px; color:#999;">&nbsp;</p>
        <p style=" font-size:18px; line-height:26px; color:#999;"><strong>-</strong> One video shown below is shot using our algorithm, and the other was filmed in a different way. The left-to-right ordering is determined randomly. </p>
        <p style=" font-size:18px; line-height:26px; color:#999;">&nbsp;</p>
      <p style=" font-size:18px; line-height:26px; color:#999;"><strong>-</strong> To increase the efficiency, all videos are compressed into 1920*1080 and speeded up about 5 times.</p>
      <p style=" font-size:18px; line-height:26px; color:#999;">&nbsp;</p></td>
    </tr>
    <tr>
      <td><p>&nbsp;</p></td>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
    </tr>
  </table>
</div>

<div style="width:1290px; margin:auto;">
<hr style=" height:1px;border:none;border-top:1px solid #ccc;" />
  <p>&nbsp;</p>
  <table width="100%" border="0" cellpadding="0">
    <tr>
      <td>
        <video width="644" height="363" controls> 
       <source src="videos/<?php echo($Real_sample_ID."/".$First_video_name.".mp4"); ?>" type="video/mp4"> 
        您的浏览器不支持此种视频格式。 
       </video> 
      </td>
      <td>
       <video width="644" height="363" controls> 
       <source src="videos/<?php echo($Real_sample_ID."/".$Second_video_name.".mp4"); ?>" type="video/mp4"> 
       您的浏览器不支持此种视频格式。 
       </video> 
      </td>
    </tr>
    <tr>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
    </tr>
  </table>
  <form id="form1" name="form_voting" method="post" action="vote.php" onsubmit="return formCheck()">
  <table style=" margin:auto" width="90%" border="0" cellpadding="0">
    <tr>
      <td width="79%"><strong>Q1: The left video was more pleasing to watch than the right one.</strong></td>
      <td width="4%" rowspan="8">&nbsp;</td>
      <td width="17%" rowspan="8">
      <input type="image" src="img/next.png" width="182" height="171"  /></td>
    </tr>
    <tr>
      <td>
        <input type="radio" name="Which_is_better_one" id="radio" value="<?php echo ($First_video_name.$Second_video_name."_+_2");?>" />
        <label for="radio"></label>
        completely agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_one" id="radio2" value="<?php echo ($First_video_name.$Second_video_name."_+_1");?>" />
        somewhat agree  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_one" id="radio3" value="<?php echo ($First_video_name.$Second_video_name."_+_0");?>" />
        neutral  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_one" id="radio4" value="<?php echo ($First_video_name.$Second_video_name."_-_1");?>" />
        somewhat disagree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_one" id="radio5" value="<?php echo ($First_video_name.$Second_video_name."_-_2");?>" />
        completely disagree <br />
      </td>
    </tr>
    <tr>
      <td><p>&nbsp;</p><hr style=" height:1px;border:none;border-top:1px dotted #ccc;" /><p>&nbsp;</p>
      <p><strong>Q2: The left video provides a clearer overview of the landmarks we want to explore than the right one.</strong></p>
      </td>
    </tr>
    <tr>
      <td>
        <input type="radio" name="Which_is_better_two" id="radio6" value="<?php echo ($First_video_name.$Second_video_name."_+_2");?>" />
        <label for="radio6"></label>
        completely agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="radio" name="Which_is_better_two" id="radio7" value="<?php echo ($First_video_name.$Second_video_name."_+_1");?>" />
        somewhat agree  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="radio" name="Which_is_better_two" id="radio8" value="<?php echo ($First_video_name.$Second_video_name."_+_0");?>" />
        neutral  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="radio" name="Which_is_better_two" id="radio9" value="<?php echo ($First_video_name.$Second_video_name."_-_1");?>" />
        somewhat disagree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="radio" name="Which_is_better_two" id="radio10" value="<?php echo ($First_video_name.$Second_video_name."_-_2");?>" />
        completely disagree <br />
      </td>
    </tr>
    <tr>
      <td>
      <p>&nbsp;</p><hr style=" height:1px;border:none;border-top:1px dotted #ccc;" /><p>&nbsp;</p>
      <p><strong>Q3: The left video follows a more reasonable route than the right one.</strong></p></td>
    </tr>
    <tr>
      <td>
        <input type="radio" name="Which_is_better_three" id="radio11" value="<?php echo ($First_video_name.$Second_video_name."_+_2");?>" />
        <label for="radio11"></label>
        completely agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_three" id="radio12" value="<?php echo ($First_video_name.$Second_video_name."_+_1");?>" />
        somewhat agree  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_three" id="radio13" value="<?php echo ($First_video_name.$Second_video_name."_+_0");?>" />
        neutral  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_three" id="radio14" value="<?php echo ($First_video_name.$Second_video_name."_-_1");?>" />
        somewhat disagree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_three" id="radio15" value="<?php echo ($First_video_name.$Second_video_name."_-_2");?>" />
        completely disagree <br />
      </td>
    </tr>

        <tr>
      <td>
      <p>&nbsp;</p><hr style=" height:1px;border:none;border-top:1px dotted #ccc;" /><p>&nbsp;</p>
      <p><strong>Q4: The transitions between the landmarks are more pleasing on the left video.</strong></p></td>
    </tr>
    <tr>
      <td>
        <input type="radio" name="Which_is_better_four" id="radio16" value="<?php echo ($First_video_name.$Second_video_name."_+_2");?>" />
        <label for="radio11"></label>
        completely agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_four" id="radio17" value="<?php echo ($First_video_name.$Second_video_name."_+_1");?>" />
        somewhat agree  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_four" id="radio18" value="<?php echo ($First_video_name.$Second_video_name."_+_0");?>" />
        neutral  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_four" id="radio19" value="<?php echo ($First_video_name.$Second_video_name."_-_1");?>" />
        somewhat disagree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_four" id="radio20" value="<?php echo ($First_video_name.$Second_video_name."_-_2");?>" />
        completely disagree <br />
      </td>
    </tr>

        <tr>
      <td>
      <p>&nbsp;</p><hr style=" height:1px;border:none;border-top:1px dotted #ccc;" /><p>&nbsp;</p>
      <p><strong>Q5: The trajectory of the drone was smoother in the left video.</strong></p></td>
    </tr>
    <tr>
      <td>
        <input type="radio" name="Which_is_better_five" id="radio21" value="<?php echo ($First_video_name.$Second_video_name."_+_2");?>" />
        <label for="radio11"></label>
        completely agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_five" id="radio22" value="<?php echo ($First_video_name.$Second_video_name."_+_1");?>" />
        somewhat agree  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_five" id="radio23" value="<?php echo ($First_video_name.$Second_video_name."_+_0");?>" />
        neutral  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_five" id="radio24" value="<?php echo ($First_video_name.$Second_video_name."_-_1");?>" />
        somewhat disagree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <input type="radio" name="Which_is_better_five" id="radio25" value="<?php echo ($First_video_name.$Second_video_name."_-_2");?>" />
        completely disagree <br />
      </td>
    </tr>

      </form>
    
  </table>

  <input name="Usr_Info_Gender" type="hidden"  value="<?php echo($Usr_Info_Gender);?>" />
  <input name="Usr_Info_Age" type="hidden"  value="<?php echo($Usr_Info_Age);?>" />
  <input name="Usr_Info_Pilot" type="hidden"  value="<?php echo($Usr_Info_Pilot);?>" />

  <input type="hidden" name="First_video_name" value="<?php echo($First_video_name)?>">
    <input type="hidden" name="Second_video_name" value="<?php echo($Second_video_name)?>">
  <input type="hidden" name="Is_new_voting" value="false">
  <input type="hidden" name="Samples_ID_Sequence" value="<?php echo($Samples_ID_Sequence)?>">
  <input type="hidden" name="User_Answers" value="<?php echo($User_Answers)?>">
  <input type="hidden" name="NumHasDid" value="<?php echo($NumHasDid);?>">
  <input type="hidden" name="Starttime" value="<?php echo($Starttime);?>">

  <br />
  <br />
</div>
<div style=" background:url(img/web_go.jpg) repeat-x; height:85px;"></div>

  <?php
  
  }
  else  if($NumHasDid >= count($Video_names_need_to_be_compared_true))
  {
  ?>

  <script language="javascript">
  setTimeout("document.form2.submit()",100);
  </script>

  <form name="form2" method="post" action="comment.php">
  <?php $User_Answers = $User_Answers."\n".$Usr_Info_Age."|\t\t\t".$Usr_Info_Gender."|\t\t\t".$Usr_Info_Pilot;?>
  <input name="User_Answers" type="hidden"  value="<?php echo($User_Answers);?>" />

  </form>
  <?php
  }
  ?>



</body>
</html>
