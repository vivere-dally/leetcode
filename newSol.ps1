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
$dirName = "${PSScriptRoot}/src/${Difficulty}/${Id}_${fName}"
$mdFileName = "$dirName/README.md"

New-Item -Path $dirName -ItemType Directory | Out-Null
New-Item -Path $mdFileName -ItemType File | Out-Null

$content, $fileName = switch (Get-Random -Minimum 0 -Maximum 2) {
    0 {
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
"@, "$dirnName/main.cpp"
        break;
    }
    1 {
        @"
// Solution class here

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.);
    }
}
"@, "$dirName/Main.java"
        break;
    }
}


New-Item -Path $fileName -ItemType File | Out-Null
$content | Set-Content -Path $fileName -Encoding utf8

Write-Host 'Happy coding!' -ForegroundColor Green
