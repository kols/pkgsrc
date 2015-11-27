$NetBSD: patch-src_fsq_fsq.cxx,v 1.4 2015/11/20 14:29:17 joerg Exp $

Resolve conflict between std::next and the local variable of the same name.
std::complex::imag() and std::complex::real() are not lvalues.

--- src/fsq/fsq.cxx.orig	2015-09-28 18:24:41.000000000 +0000
+++ src/fsq/fsq.cxx
@@ -1195,9 +1195,12 @@ int fsq::rx_process(const double *buf, i
 						&rx_stream[SHIFT_SIZE],				// from
 						BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
-				for (int i = 0; i < BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+				for (int i = 0; i < BLOCK_SIZE; i++) {
+					double r = rx_stream[i] * a_blackman[i];
+					fft_data[i].real(r);
+					fft_data[i].imag(r);
+				}
+						
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
@@ -1426,7 +1429,7 @@ static string tx_text_queue = "";
 
 static vector<string> commands;
 #define NUMCOMMANDS 10
-static size_t next = 0;
+static size_t nextidx = 0;
 
 void  clear_xmt_arrays()
 {
@@ -1450,9 +1453,9 @@ double fsq_xmtdelay() // in seconds
 void fsq_repeat_last_command()
 {
 	fsq_tx_text->clear();
-	fsq_tx_text->addstr(sz2utf8(commands[next].c_str()));
-	next++;
-	if (next == commands.size()) next = 0;
+	fsq_tx_text->addstr(sz2utf8(commands[nextidx].c_str()));
+	nextidx++;
+	if (nextidx == commands.size()) nextidx = 0;
 }
 
 int get_fsq_tx_char(void)
@@ -1494,7 +1497,7 @@ void try_transmit(void *)
 	if (active_modem != fsq_modem) return;
 
 	if (!active_modem->fsq_squelch_open() && trx_state == STATE_RX) {
-		next = 0;
+		nextidx = 0;
 		fsq_que_clear();
 //LOG_WARN("%s", "start_tx()");
 		start_tx();
