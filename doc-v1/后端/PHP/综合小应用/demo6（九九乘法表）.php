<style type="text/css">
table {width:980px;margin:auto;border-collapse:collapse;}
td {border:#000 solid 1px;padding-left:10px;}
</style>

<?php
echo '<table>';
for($i=1;$i<=9;$i++)
{
    echo '<tr>';
    for($j=1;$j<=$i;$j++)
    {
    echo "<td>{$j}X{$i}=" . ($j*$i) . "</td>";
    }
    echo '</tr>';
}
echo '</table>';