import java.util.ArrayList;
import java.util.Iterator;
import java.io.IOException;
import java.io.FileNotFoundException;
//import java.io.Writer;
import java.io.BufferedWriter;
import java.io.FileWriter;
//import java.io.Reader;
import java.io.FileReader;
import java.net.URISyntaxException;
import java.io.File;
import java.io.PrintWriter;
import java.io.BufferedReader;

// 
// Decompiled by Procyon v0.5.36
// 

public class FileIO
{
    public static final int FOR_READING = 1;
    public static final int FOR_WRITING = 2;
    private int setting;
    private BufferedReader br;
    private PrintWriter pw;
    private boolean EOF;
    private boolean tokens;
    private String delimiter;
    
    public FileIO(final String name, final int setting) throws FileIOException {
        this.EOF = false;
        try {
            if (setting != 1 && setting != 2) {
                throw new FileIOException("Must specify reading or writing.");
            }
            this.setting = setting;
            File file;
            try {
                file = new File(this.getClass().getResource(name).toURI());
            }
            catch (URISyntaxException ex) {
                throw new FileIOException(ex.getMessage());
            }
            if (this.setting == 1) {
                this.br = new BufferedReader(new FileReader(file));
            }
            else if (this.setting == 2) {
                this.pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
            }
        }
        catch (FileNotFoundException ex2) {
            throw new FileIOException("File not found.");
        }
        catch (IOException ex3) {
            throw new FileIOException("IO Error");
        }
    }
    
    public FileIO(final String name, final String delimiter) throws FileIOException {
        this.EOF = false;
        try {
            this.setting = 1;
            this.tokens = true;
            this.delimiter = delimiter;
            File file;
            try {
                file = new File(this.getClass().getResource(name).toURI());
            }
            catch (URISyntaxException ex) {
                throw new FileIOException(ex.getMessage());
            }
            this.br = new BufferedReader(new FileReader(file));
        }
        catch (FileNotFoundException ex2) {
            throw new FileIOException("File not found.");
        }
    }
    
    public Iterator<String> getTokens() throws FileIOException {
        ArrayList<String> list = new ArrayList<String>();
        if (this.tokens && !this.EOF) {
            final String line = this.readLine();
            if (!this.EOF) {
                final String[] split = line.split(this.delimiter);
                list = new ArrayList<String>();
                final String[] array = split;
                for (int length = array.length, i = 0; i < length; ++i) {
                    list.add(array[i]);
                }
            }
            return list.iterator();
        }
        throw new FileIOException("Tokens not available.");
    }
    
    public boolean EOF() {
        return this.EOF;
    }
    
    public String readLine() throws FileIOException {
        String line;
        try {
            if (this.setting != 1) {
                throw new FileIOException("File is not open for reading.");
            }
            line = this.br.readLine();
            if (line == null) {
                this.EOF = true;
            }
        }
        catch (IOException ex) {
            throw new FileIOException("IO Error");
        }
        return line;
    }
    
    public void writeLine(final String x) throws FileIOException {
        if (this.setting == 2) {
            this.pw.println(x);
            return;
        }
        throw new FileIOException("File is not open for writing.");
    }
    
    public void close() throws FileIOException {
        try {
            if (this.setting == 1) {
                this.br.close();
                this.setting = -1;
                this.br = null;
            }
            else if (this.setting == 2) {
                this.pw.close();
                this.setting = -1;
                this.pw = null;
            }
        }
        catch (IOException ex) {
            throw new FileIOException("IO Error");
        }
    }
}