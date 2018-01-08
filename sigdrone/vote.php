<!-- for drone project -->
<?php include 'settings.php'?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Voting</title>

<link rel="stylesheet" href="style/style.css">
<link rel="stylesheet" href="style/common.css">
<link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon">
 <script src="style/jquery.min.js"></script>

 <SCRIPT LANGUAGE=JavaScript>

function formCheck()
{
    var flag1 = false;
	var flag2 = false;
	var flag3 = false;
	var flag4 = false;

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
	if(document.form_voting.Feelings.value.length > 0)
		flag4 = true;

    if(!(flag1 && flag2 && flag3 && flag4))
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
    <div class="content vote-page" >

    <?php include 'data.php';?>
    <?php

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
	$Feelings = $_POST["Feelings"];

	
	function microtime_float()
    {
		list($usec, $sec) = explode(" ", microtime());
		return ((float)$usec + (float)$sec);
	}
	if($Which_is_better_one != "" )
	{
		$User_Answers = $User_Answers."\n1: ".$Which_is_better_one;
		$User_Answers = $User_Answers."\t\t\t2: ".$Which_is_better_two;
		$User_Answers = $User_Answers."\t\t\t3: ".$Which_is_better_three;
		$User_Answers = $User_Answers."\t\t\t4: ".$Feelings;

		$starttime = $_POST["Starttime"];
		$endtime = microtime_float();	
		$runtime = number_format($endtime - (float)$starttime, 4).'s';	
    
		$User_Answers = $User_Answers."\t time: ".$runtime;
	}
	

	if (!($Is_new_voting=="false"))
	{
		$Is_new_voting = "true";
		$Samples_ID_Sequence_array = range(1,count($Video_names_need_to_be_compared_true));
		
		// $Samples_ID_Sequence_array_sub1 = range(1,count($Video_names_need_to_be_compared_true)/2);
		// $Samples_ID_Sequence_array_sub2 = range(intval(count($Video_names_need_to_be_compared_true)/2) + 1,count($Video_names_need_to_be_compared_true));
		
		// shuffle($Samples_ID_Sequence_array_sub1);
		// shuffle($Samples_ID_Sequence_array_sub2);
		
		// // while(($Samples_ID_Sequence_array_sub2[0] - $Samples_ID_Sequence_array_sub1[count($Video_names_need_to_be_compared_true)/2 - 1]) == 2)
		// // {
		// // 	shuffle($Samples_ID_Sequence_array_sub2);
		// // }
		
		// $Samples_ID_Sequence_array = array_merge($Samples_ID_Sequence_array_sub1, $Samples_ID_Sequence_array_sub2);  
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
<div style="width:1280px; margin:auto;" align="center">


  <table width="100%" border="0">
	<tr>&nbsp;</tr>
    <tr>
       <td width=45% align="right">
       <img src="videos/<?php echo($Real_sample_ID."/".($Real_sample_ID)."_pic.png"); ?>" height = "360" width="640" align="middle" >
  
       </img> 
       </td>

       <td width=5% align="center"></td>
  
  
       <td width=50% align="left" rowspan="10">
       	
			<p><strong>All the places marked red in left are places we want to explore.</strong></p>
			<p><strong>One of the videos below are aerial video shooted by our algotrithm, the other is filmed manully or by other tools.</strong></p>
			<p><strong>To increase the efficiency, all the video are speeded up to relate short duration. And they are randomly placed.</strong></p>
			<p><strong>We value your opinions!</strong></p>
     
       </td>
    </tr>

  </table>
  
  <table width="100%" border="0">

    <tr>
       <td width=45% align="right">
       <video width="640" height="360" controls> 
       <source src="videos/<?php echo($Real_sample_ID."/".$First_video_name.".mp4"); ?>" type="video/mp4"> 
        您的浏览器不支持此种视频格式。 
       </video> 
       </td>

       <td width=10% align="center"></td>
  
  
       <td width=45% align="left">
       <video width="640" height="360" controls> 
       <source src="videos/<?php echo($Real_sample_ID."/".$Second_video_name.".mp4"); ?>" type="video/mp4"> 
       您的浏览器不支持此种视频格式。 
       </video> 
       </td>
    </tr>
  </table>
 </div>

  <form name="form_voting"  method="post" action="vote.php" onsubmit="return formCheck()">
    <table style=" margin:auto;" width="1200" border="0" align="center">
	    <tr>
			<td colspan="10"><strong>Q1: The left video was more pleasing to watch than the right one.</strong></td>
        </tr>
		<tr>
			<td><input name="Which_is_better_one" type="radio"  value="<?php echo ($First_video_name."&+2&".$Second_video_name);?>"></td>
			<td>completely agree</td>
			<td><input name="Which_is_better_one" type="radio"  value="<?php echo ($First_video_name."&+1&".$Second_video_name);?>"></td>
			<td>somewhat agree</td>
			<td><input name="Which_is_better_one" type="radio"  value="<?php echo ($First_video_name."&0&".$Second_video_name);?>"></td>
			<td>neutral</td>
			<td><input name="Which_is_better_one" type="radio"  value="<?php echo ($First_video_name."&-1&".$Second_video_name);?>"></td>
			<td>somewhat disagree</td>
			<td><input name="Which_is_better_one" type="radio"  value="<?php echo ($First_video_name."&-2&".$Second_video_name);?>"></td>
			<td>completely disagree</td>
		</tr>

		<tr>
			<td colspan="10"><strong>Q2: The left video provides a clearer overview of the landmarks we want to explore than the right one.</strong></td>
        </tr>
		<tr>
			<td><input name="Which_is_better_two" type="radio"  value="<?php echo ($First_video_name."&+2&".$Second_video_name);?>"></td>
			<td>completely agree</td>
			<td><input name="Which_is_better_two" type="radio"  value="<?php echo ($First_video_name."&+1&".$Second_video_name);?>"></td>
			<td>somewhat agree</td>
			<td><input name="Which_is_better_two" type="radio"  value="<?php echo ($First_video_name."&0&".$Second_video_name);?>"></td>
			<td>neutral</td>
			<td><input name="Which_is_better_two" type="radio"  value="<?php echo ($First_video_name."&-1&".$Second_video_name);?>"></td>
			<td>somewhat disagree</td>
			<td><input name="Which_is_better_two" type="radio"  value="<?php echo ($First_video_name."&-2&".$Second_video_name);?>"></td>
			<td>completely disagree</td>
		</tr>
		<tr>
			<td colspan="10"><strong>Q3: The left video follows a more reasonable route than the right one.</strong></td>
        </tr>
		<tr>
			<td><input name="Which_is_better_three" type="radio"  value="<?php echo ($First_video_name."&+2&".$Second_video_name);?>"></td>
			<td>completely agree</td>
			<td><input name="Which_is_better_three" type="radio"  value="<?php echo ($First_video_name."&+1&".$Second_video_name);?>"></td>
			<td>somewhat agree</td>
			<td><input name="Which_is_better_three" type="radio"  value="<?php echo ($First_video_name."&0&".$Second_video_name);?>"></td>
			<td>neutral</td>
			<td><input name="Which_is_better_three" type="radio"  value="<?php echo ($First_video_name."&-1&".$Second_video_name);?>"></td>
			<td>somewhat disagree</td>
			<td><input name="Which_is_better_three" type="radio"  value="<?php echo ($First_video_name."&-2&".$Second_video_name);?>"></td>
			<td>completely disagree</td>
		</tr>

			<td colspan="10"><strong>Q4: Any other feelings or thoughts, please comment below:</strong></td>
        </tr>
		<tr>
			<td colspan="10"><input name="Feelings" type="text"  style="width:100%; height:100%;"></td>
		</tr>
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


	<td>&nbsp;</td>
	<div style="width:120px; margin: auto;";>
	
	<input type="submit" name="submit" value="" style="background:url('img/next.png') no-repeat; width:65px; height:36px;">
    </div>
	
  </form>

  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
  <p>&nbsp;</p>
   </div>
    
	<?php
	
	}
	else  if($NumHasDid >= count($Video_names_need_to_be_compared_true))
	{
	?>

	<script language="javascript">
	setTimeout("document.form2.submit()",100);
	</script>

	<form name="form2" method="post" action="result.php">
	<?php $User_Answers = $User_Answers."\nSubject age: ".$Usr_Info_Age."\t\t\t Subject Gender: ".$Usr_Info_Gender."\t\t\t Subject Drone Pilot experence: ".$Usr_Info_Pilot;?>
	<input name="User_Answers" type="hidden"  value="<?php echo($User_Answers);?>" />

	</form>
	<?php
	}
	?>
	</div>
    </body>

</html>