# WaitR
C++ File Distribution Sytem

In menu:
	1) Config
		Shows popup with textboxes
		Fill text boxes
		Choose if you want to rewrite on that server or backup
	
	2) Copy
		Choose source folder
		Enter suffix for folder name
			if suffix not filled it will just write source folde name
			else source folder name "_" suffix
		Choose locations oh which you want to copy
		Hit ok to copy
Log:
	Log file will be created.
	After program is done chceck log file for errors atc.

WaitR will copy files from one source to multiple locations
WaitR expects exact source folder structure 
	..[Folder we want to copy from] 
		.[App folder with program files (important to have)]
			.[files we want to copy (important to have)]
		.[DB folder (not realy needed for this program but the others need it)]
		.[Reports folder(not realy needed for this program but the others need it)]
		.[readme.txt file (not needed)]

WaitR will create following structure if back up is needed
	..[Backup folder location]	
		..[Folder we want to copy from] 
			.[App folder with program files]
				.[Backup folder (created by WaitR)]
					.[if files from App folder exists in program folder then backup them here]
				.[copied new files from source]
			.[DB folder (not realy needed for this program but the others need it)]
			.[Reports folder(not realy needed for this program but the others need it)]
			.[readme.txt file (not needed)]
