<?php include 'settings.php'?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN">


<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon">
<?php     $User_Answers = (string)$_POST["User_Answers"]."\n".(string)$_POST["Feelings"];  $User_Answers = trim($User_Answers);  ?>

 <?php
    $Filename = date('Y-m-j')."--".date('G-i-s');
    $Filename = "Scores_By_User/".$_SERVER["REMOTE_ADDR"]."_".((string)$Filename)."-".((string)mt_rand(100000000, 999999999)).".txt";

    $Answers = explode("<br>",$User_Answers);

	$Answers_true = "";

	$Array_sub_answers = array();
	$Num_of_lines = 0;
	for ($i=0; $i<count($Answers); ++$i)
	{

			$Answer_tmp = trim($Answers[$i]);

			if ( strlen($Answer_tmp) > 3)
			{
				$Answer_tmp_tmp = explode(" ",$Answer_tmp);
				$Answer_tmp_tmp_tmp = explode("_",$Answer_tmp_tmp[0]);

				$Answer_tmp_index = (int)($Answer_tmp_tmp_tmp[0]);
				$Array_sub_answers[$Answer_tmp_index] = $Answer_tmp;
				$Num_of_lines++;
			}

	}

	for ($i=1; $i < ($Num_of_lines + 1); ++$i)
	{
		$Answers_true = $Answers_true.$Array_sub_answers[$i]."\n";
	}

	$file_handle2 = fopen($Filename, "w");

	$Answers_true = $User_Answers;
	fwrite($file_handle2, $Answers_true);
	fclose($file_handle2);
?>
<title></title>


	<META HTTP-EQUIV="Refresh" CONTENT="0;URL=done.php ">


</head>

    <body>
<?php // echo($User_Answers);
?>
    </body>

</html>