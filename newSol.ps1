[CmdletBinding()]
param (
    [Parameter(Mandatory = $true)]
    [ValidateSet('easy', 'medium', 'hard')]
    [string]
    $Difficulty,

    [Parameter(Mandatory = $true)]
    [string]
    $Id,

    [Parameter(Mandatory = $true)]
    [string]
    $Name
)

$fName = $Name.Split(' ')
$fName[0] = $fName[0].ToLowerInvariant()
$fName = $fName -join ''
$dirName = "${PSScriptRoot}/src/${Difficulty}_${Id}_${fName}"
$cppFileName = "$dirName/main.cpp"
$mdFileName = "$dirName/README.md"

New-Item -Path $dirName -ItemType Directory | Out-Null
New-Item -Path $cppFileName -ItemType File | Out-Null
New-Item -Path $mdFileName -ItemType File | Out-Null

@"
#include <iostream>
using namespace std;

// Solutin class here

int main()
{
    Solution s;
    cout << s. << endl;
    return 0;
}
"@ | Set-Content -Path $cppFileName -Encoding utf8

Write-Host 'Happy coding!' -ForegroundColor Green
