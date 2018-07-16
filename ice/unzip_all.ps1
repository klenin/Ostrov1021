Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip
{
    param([string]$zipfile, [string]$outpath)
    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
}

$shell = New-Object -ComObject shell.application
$zip = $shell.NameSpace("C:\OSTROV\2015\")
foreach ($item in $zip.items()) {
	$path = "C:\OSTROV\"
	$path += $item.Name.Substring(0, $item.Name.LastIndexOf('.'))
	echo $path
	Unzip $item.Path $path
}

