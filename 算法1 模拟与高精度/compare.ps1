CLear-Host
$a = Get-Content "C:\Users\adela\Desktop\template_msword zh\``[Content_Types``].xml"
$b = Get-Content "C:\Users\adela\Desktop\template_msword\``[Content_Types``].xml"
Compare-Object $a $b -IncludeEqual