Add-Type -AssemblyName System.IO.Compression.FileSystem

$path_to_glance = "C:\Glance 2.0\Glance.exe"
$path_to_ini_file = "C:\Glance 2.0\Samples\convert_chl_oc322.ini"

$shell = New-Object -ComObject shell.application
$dir = $shell.NameSpace("C:\OSTROV")
foreach ($item in $dir.items()) {
	if ($item.IsFolder){
		echo $item
		$Folder = $shell.NameSpace($item.Path)
		foreach ($file in $Folder.items()){
			& $path_to_glance $path_to_ini_file $file.path | Out-Null
		}
	}
}