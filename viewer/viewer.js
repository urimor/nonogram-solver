$(document).ready(function documentReady() {
    console.log("ready!!");
    $.getJSON("board.json", function get_json(data){
        var numberOfColumns = data["column-descriptors"].length;
        var numberOfRows = data["column-descriptors"].length;
        var lengthOfColumnDescriptors = maxSubArrayLength(data["column-descriptors"]);
        var lengthOfRowDescriptors = maxSubArrayLength(data["row-descriptors"]);

        padDescriptors();
        createColumnDescriptors();
        createRowDescriptors();
        createMainBoard();

        console.log(data);
        console.log("number Of columns = " + numberOfColumns);
        console.log("number Of rows = " + numberOfRows);
        console.log("length of column descriptors = " + lengthOfColumnDescriptors);
        console.log("length of row descriptors = " + lengthOfRowDescriptors);

        function padDescriptors(){
            padDescriptorsToMatchMaxLength(data["column-descriptors"]);
            padDescriptorsToMatchMaxLength(data["row-descriptors"]);
        }

        function createColumnDescriptors(){
            var $table = $("<table></table>");

            for(var i = 0; i < lengthOfColumnDescriptors ; i++){
                var $tableRow = $("<tr></tr>");
                var columnCounter = 0;
                _(data["column-descriptors"]).forEach(function(descriptor){
                    var $tableCell = $("<td></td>");
                    $tableCell.text(descriptor[i]);
                    $tableCell.addClass("cell descriptor-cell");
                    if(columnCounter % 5 === 0){
                        $tableCell.addClass("first-column-in-block");
                    }
                    $tableRow.append($tableCell);
                    columnCounter++;
                })
                $table.append($tableRow);
                $table.addClass("line-descriptors-container");
            }

            $("#column-descriptors").append($table);
        }

        function createRowDescriptors(){
            var $table = $("<table></table>");
            var rowCounter = 0;
            _(data["row-descriptors"]).forEach(function(descriptor){
                var $tableRow = $("<tr></tr>");
                _(descriptor).forEach(function(value){
                    var $tableCell = $("<td></td>");
                    $tableCell.text(value);
                    $tableCell.addClass("cell descriptor-cell");
                    if(rowCounter % 5 === 0){
                        $tableCell.addClass("first-row-in-block");
                    }
                    $tableRow.append($tableCell);
                })
                rowCounter++;
                $table.append($tableRow);
                $table.addClass("line-descriptors-container");
            })
            $("#row-descriptors").append($table);
        }

        function createMainBoard(){
            var $table = $("<table></table>");
            var rowCounter = 0;
            _(data["main-board"]).forEach(function(row){
                var $tableRow = $("<tr></tr>");
                var columnCounter = 0;
                _(row).forEach(function(square){
                    var $tableCell = $("<td></td>");
                    switch (square){
                        case 0:
                            $tableCell.text(" ");
                            $tableCell.addClass("cell square-empty");
                            break;
                        case 1:
                            $tableCell.text(" ");
                            $tableCell.addClass("cell square-full");
                            break;
                        case 2:
                            $tableCell.text("X");
                            $tableCell.addClass("cell square-x");
                            break;
                    }
                    if(rowCounter % 5 === 0){
                        $tableCell.addClass("first-row-in-block");
                    }
                    if(columnCounter % 5 === 0){
                        $tableCell.addClass("first-column-in-block");
                    }
                    columnCounter++;
                    $tableRow.append($tableCell);
                })
                rowCounter++;
                $table.append($tableRow);
                $table.addClass("main-board-container");
            })
            $("#main-board").append($table);
        }

        function padDescriptorsToMatchMaxLength (descriptorsArray) {
            var lengthOfDescriptors = maxSubArrayLength(descriptorsArray);
            _(descriptorsArray).forEach(function(descriptor){
                var descriptorLength = descriptor.length;
               for(var i = 0; i < lengthOfDescriptors - descriptorLength; i++){
                    descriptor.unshift("");
               }
            });
        }

        function maxSubArrayLength(array) {
            var maxColumnDescriptorLength = 0;
            _(array).forEach(function (element) {
                if (element.length > maxColumnDescriptorLength) {
                    maxColumnDescriptorLength = element.length;
                }
            });
            return maxColumnDescriptorLength;
        }

    });

})
