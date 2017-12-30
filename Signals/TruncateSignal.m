%%
% Обрезка файла для дальнешей удобной обработки
 

%%
%
clear;

filename = 'rx_randi_20ofdm_20000pckt_15.dat';
firstComplexSampleNo = uint64( 1 * 10^7 );
endComplexSampleNo   = uint64( 5.42 * 10^7 );
envelope_graph = 'display'; % 'display' or 'no_display'

filename_original = [ './RxBaseband_ComplexFloat32_bin/', ...
                      filename ];
filename_result   = [ './RxBaseband_Truncate_ComlexFloat32_bin/', ...
                      [filename(1:3), 'tr_', filename(4 : end)] ];

% filename_result   = filename_original;


%%

if exist(filename_result, 'file') ~= 0
	fprintf('"%s" is exist! Exit\n', filename_result);
	return;
end

fd = fopen(filename_original, 'r');
if fd == -1
    error('File is not opened');  
end
rxSig = fread(fd, [1, inf], 'float32=>float32');
fclose(fd);

rxSig = rxSig(2 * firstComplexSampleNo - 1 : 2 * endComplexSampleNo);

fd = fopen(filename_result, 'w');
if fd == -1
    error('File is not opened');  
end
fwrite(fd, rxSig, 'float32');
fclose(fd);

if strcmp(envelope_graph, 'display')

	envelope = abs( double(rxSig(1 : 2 : end)) + 1i * double(rxSig(2 : 2 : end)) );
	figure;
	plot(envelope);
	grid on;
	xlabel('sample');
	ylabel('abs(rxIQ)');
	title('Truncated Complex Envelope')

end
