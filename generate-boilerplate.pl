#!/usr/bin/perl
use strict;
use warnings;

my $USAGE = <<EOT;

./generate-boilerplate.pl [LIBRARY] [OBJECT]

Use this script to generate your boilerplate library. The new library will be
generated into the directory `./[LIBRARY]` and will contain one object called
`[OBJECT]`.

Example:

    ./generate-boilerplate.pl gdk window

EOT

die "Couldn't find maman-bar header" unless -f './maman/maman-bar.h';

unless (@ARGV == 2) {
    print $USAGE;
    exit(@ARGV ? 1 : 0);
}

my $library_name = lc $ARGV[0];
my $object_name = lc $ARGV[1];

mkdir "./$library_name" or die "cannot mkdir '$library_name': $!";
mkdir "./$library_name/$library_name" or die "cannot mkdir '$library_name/$library_name: $!";
my @files = qw(Makefile.am configure.ac autogen.sh maman/Makefile.am maman/maman-bar.c maman/maman-bar.h);

print "------------------\n";
print "maman ~ $library_name\n";
print "bar ~ $object_name\n";
print "------------------\n";

foreach my $file_in (@files) {
    my $file_out = $file_in =~ s/maman/$library_name/rg;
    $file_out =~ s/bar/$object_name/g;
    $file_out = "$library_name/$file_out";

    open my $fh_in, "<", $file_in or die $!;
    open my $fh_out, ">", $file_out or die $!;

    while (my $line = <$fh_in>) {
        $line =~ s/maman/$library_name/g;
        $line =~ s/Maman/ucfirst($library_name)/eg;
        $line =~ s/MAMAN/uc($library_name)/eg;

        $line =~ s/bar/$object_name/g;
        $line =~ s/Bar/ucfirst($object_name)/eg;
        $line =~ s/BAR/uc($object_name)/eg;

        print $fh_out $line;
    }

    print "$file_in ~ $file_out\n";

    close $fh_in;
    close $fh_out;

    chmod(0755, $file_out) if $file_in =~ /autogen\.sh/;

}

exit 0;
